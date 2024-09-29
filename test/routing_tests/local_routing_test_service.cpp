// Copyright (C) 2015 Bayerische Motoren Werke Aktiengesellschaft (BMW AG)
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "local_routing_test_service.hpp"

local_routing_test_service::local_routing_test_service(bool _use_static_routing) :
                app_(vsomeip::runtime::get()->create_application()),
                is_registered_(false),
                blocked_(false),
                use_static_routing_(_use_static_routing),
                offer_thread_(std::bind(&local_routing_test_service::run, this)),
                number_of_received_messages_(0)
{
}

void local_routing_test_service::init()
{
    std::lock_guard<std::mutex> its_lock(mutex_);

    app_->init();
    app_->register_message_handler(vsomeip_test::TEST_SERVICE_SERVICE_ID,
            vsomeip_test::TEST_SERVICE_INSTANCE_ID, vsomeip_test::TEST_SERVICE_METHOD_ID,
            std::bind(&local_routing_test_service::on_message, this,
                    std::placeholders::_1));

    app_->register_event_handler(
            std::bind(&local_routing_test_service::on_event, this,
                    std::placeholders::_1));

    VSOMEIP_INFO << "Static routing " << (use_static_routing_ ? "ON" : "OFF");
}

void local_routing_test_service::start()
{
    VSOMEIP_INFO << "Starting...";
    app_->start();
}

void local_routing_test_service::stop()
{
    VSOMEIP_INFO << "Stopping...";
    app_->unregister_message_handler(vsomeip_test::TEST_SERVICE_SERVICE_ID,
            vsomeip_test::TEST_SERVICE_INSTANCE_ID, vsomeip_test::TEST_SERVICE_METHOD_ID);
    app_->unregister_event_handler();
    app_->stop();
}

void local_routing_test_service::join_offer_thread()
{
    offer_thread_.join();
}

void local_routing_test_service::offer()
{
    app_->offer_service(vsomeip_test::TEST_SERVICE_SERVICE_ID, vsomeip_test::TEST_SERVICE_INSTANCE_ID);
}

void local_routing_test_service::stop_offer()
{
    app_->stop_offer_service(vsomeip_test::TEST_SERVICE_SERVICE_ID, vsomeip_test::TEST_SERVICE_INSTANCE_ID);
}

void local_routing_test_service::on_event(vsomeip::event_type_e _event)
{
    VSOMEIP_INFO << "Application " << app_->get_name() << " is "
            << (_event == vsomeip::event_type_e::ET_REGISTERED ? "registered." :
                    "deregistered.");

    if(_event == vsomeip::event_type_e::ET_REGISTERED)
    {
        if(!is_registered_)
        {
            is_registered_ = true;
            blocked_ = true;
            // "start" the run method thread
            condition_.notify_one();
        }
    }
    else
    {
        is_registered_ = false;
    }
}

void local_routing_test_service::on_message(const std::shared_ptr<vsomeip::message>& _request)
{
    VSOMEIP_INFO << "Received a message with Client/Session [" << std::setw(4)
            << std::setfill('0') << std::hex << _request->get_client() << "/"
            << std::setw(4) << std::setfill('0') << std::hex
            << _request->get_session() << "]";

    number_of_received_messages_++;

    ASSERT_EQ(_request->get_service(), vsomeip_test::TEST_SERVICE_SERVICE_ID);
    ASSERT_EQ(_request->get_method(), vsomeip_test::TEST_SERVICE_METHOD_ID);

    // Check the protocol version this shall be set to 0x01 according to the spec.
    // TR_SOMEIP_00052
    ASSERT_EQ(_request->get_protocol_version(), 0x01);
    // Check the message type this shall be 0xx (REQUEST) according to the spec.
    // TR_SOMEIP_00055
    ASSERT_EQ(_request->get_message_type(), vsomeip::message_type_e::MT_REQUEST);

    // make sure the message was sent from the service
    ASSERT_EQ(_request->get_client(), vsomeip_test::TEST_CLIENT_CLIENT_ID);

    // check the session id.
    ASSERT_EQ(_request->get_session(), static_cast<vsomeip::session_t>(number_of_received_messages_));


    // send response
    std::shared_ptr<vsomeip::message> its_response =
            vsomeip::runtime::get()->create_response(_request);

    app_->send(its_response, true);

    if(number_of_received_messages_ >= vsomeip_test::NUMBER_OF_MESSAGES_TO_SEND)
    {
        app_->stop();
    }
    ASSERT_LT(number_of_received_messages_,
            vsomeip_test::NUMBER_OF_MESSAGES_TO_SEND + 1);
}

void local_routing_test_service::run()
{
    std::unique_lock<std::mutex> its_lock(mutex_);
    while (!blocked_)
        condition_.wait(its_lock);

    if(use_static_routing_)
    {
        offer();
    }
}

TEST(someip_local_routing_test, receive_ten_messages_over_local_uds_socket)
{
    bool use_static_routing = true;
    local_routing_test_service test_service(use_static_routing);
    test_service.init();
    test_service.start();
    test_service.join_offer_thread();
}

#ifndef WIN32
int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#endif
