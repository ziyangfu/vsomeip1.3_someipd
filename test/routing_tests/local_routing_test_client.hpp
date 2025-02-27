// Copyright (C) 2015 Bayerische Motoren Werke Aktiengesellschaft (BMW AG)
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef LOCALROUTINGTESTCLIENT_HPP_
#define LOCALROUTINGTESTCLIENT_HPP_

#include <gtest/gtest.h>

#include <vsomeip/vsomeip.hpp>

#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>

#include "../someip_test_globals.hpp"

class local_routing_test_client
{
public:
    local_routing_test_client(bool _use_tcp);
    void init();
    void start();
    void stop();
    void join_sender_thread();
    void on_event(vsomeip::event_type_e _event);
    void on_availability(vsomeip::service_t _service,
            vsomeip::instance_t _instance, bool _is_available);
    void on_message(const std::shared_ptr<vsomeip::message> &_response);
    void send();
    void run();

private:
    std::shared_ptr<vsomeip::application> app_;
    std::shared_ptr<vsomeip::message> request_;
    std::mutex mutex_;
    std::condition_variable condition_;
    std::thread sender_;
    bool running_;
    bool blocked_;
    bool is_available_;
    std::uint32_t number_of_messages_to_send_;
    std::uint32_t number_of_sent_messages_;
    std::uint32_t number_of_acknowledged_messages_;
};

#endif /* LOCALROUTINGTESTCLIENT_HPP_ */
