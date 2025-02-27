// Copyright (C) 2014-2015 Bayerische Motoren Werke Aktiengesellschaft (BMW AG)
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <vsomeip/defines.hpp>
#include <vsomeip/message.hpp>

#include "../include/constants.hpp"
#include "../include/defines.hpp"
#include "../include/message_impl.hpp"
#include "../include/runtime_impl.hpp"
#include "../include/service_discovery_impl.hpp"

namespace vsomeip {
namespace sd {

std::shared_ptr<runtime> runtime_impl::get() {
    static std::shared_ptr<runtime> the_runtime =
            std::make_shared<runtime_impl>();
    return the_runtime;
}

runtime_impl::~runtime_impl() {
}

std::shared_ptr<service_discovery> runtime_impl::create_service_discovery(
        service_discovery_host *_host) const {
    return std::make_shared < service_discovery_impl > (_host);
}

std::shared_ptr<message_impl> runtime_impl::create_message() const {
    std::shared_ptr < message_impl > its_message =
            std::make_shared<message_impl>();
    its_message->set_service(VSOMEIP_SD_SERVICE);
    its_message->set_instance(VSOMEIP_SD_INSTANCE);
    its_message->set_method(VSOMEIP_SD_METHOD);
    its_message->set_client(VSOMEIP_SD_CLIENT);
    // session must be set dynamically
    its_message->set_protocol_version(protocol_version);
    its_message->set_interface_version(interface_version);
    its_message->set_message_type(message_type);
    its_message->set_return_code(return_code);
    return its_message;
}

} // namespace sd
} // namespace vsomeip
