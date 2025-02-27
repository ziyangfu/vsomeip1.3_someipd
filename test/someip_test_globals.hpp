// Copyright (C) 2015 Bayerische Motoren Werke Aktiengesellschaft (BMW AG)
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef SOMEIP_TEST_GLOBALS_HPP_
#define SOMEIP_TEST_GLOBALS_HPP_

#include <vsomeip/vsomeip.hpp>

namespace vsomeip_test
{

// Service
constexpr vsomeip::service_t TEST_SERVICE_SERVICE_ID = 0x1234;
constexpr vsomeip::instance_t TEST_SERVICE_INSTANCE_ID = 0x5678;
constexpr vsomeip::method_t TEST_SERVICE_METHOD_ID = 0x8421;
constexpr vsomeip::method_t TEST_SERVICE_METHOD_ID_SHUTDOWN = 0x7777;
constexpr vsomeip::client_t TEST_SERVICE_CLIENT_ID = 0x1277;

// Client local
constexpr vsomeip::client_t TEST_CLIENT_CLIENT_ID = 0x1343;

// Client external
constexpr vsomeip::client_t TEST_CLIENT_EXTERNAL_CLIENT_ID = 0x1344;


constexpr std::uint32_t NUMBER_OF_MESSAGES_TO_SEND = 10;
constexpr vsomeip::session_t TEST_INITIAL_SESSION_ID = 0x1;

constexpr std::uint32_t NUMBER_OF_MESSAGES_TO_SEND_PAYLOAD_TESTS = 1000;
constexpr vsomeip::byte_t PAYLOAD_TEST_DATA = 0xDD;
constexpr std::uint32_t MAX_PAYLOADSIZE = 1024*128;
// TR_SOMEIP_00061
constexpr std::uint32_t MAX_PAYLOADSIZE_UDP = 1400;
}

#endif /* SOMEIP_TEST_GLOBALS_HPP_ */
