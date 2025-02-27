Configuration Test
------------------
To start the configuration test from the build directory do:

./configuration-test -someip ../config/vsomeip-test.json

The expected output is:

2015-02-10 08:47:31.503874 [info] Test "HOST ADDRESS" succeeded.
2015-02-10 08:47:31.507609 [info] Test "HAS CONSOLE" succeeded.
2015-02-10 08:47:31.507865 [info] Test "HAS FILE" succeeded.
2015-02-10 08:47:31.508001 [info] Test "HAS DLT" succeeded.
2015-02-10 08:47:31.508143 [info] Test "LOGFILE" succeeded.
2015-02-10 08:47:31.508315 [info] Test "LOGLEVEL" succeeded.
2015-02-10 08:47:31.508456 [info] Test "RELIABLE_TEST_1234_0022" succeeded.
2015-02-10 08:47:31.508593 [info] Test "UNRELIABLE_TEST_1234_0022" succeeded.
2015-02-10 08:47:31.508759 [info] Test "RELIABLE_TEST_1234_0023" succeeded.
2015-02-10 08:47:31.508896 [info] Test "UNRELIABLE_TEST_1234_0023" succeeded.
2015-02-10 08:47:31.509032 [info] Test "RELIABLE_TEST_2277_0022" succeeded.
2015-02-10 08:47:31.509185 [info] Test "UNRELIABLE_TEST_2277_0022" succeeded.
2015-02-10 08:47:31.509330 [info] Test "RELIABLE_TEST_4466_0321" succeeded.
2015-02-10 08:47:31.509467 [info] Test "UNRELIABLE_TEST_4466_0321" succeeded.
2015-02-10 08:47:31.509602 [info] Test "RELIABLE_TEST_2277_0022" succeeded.
2015-02-10 08:47:31.509771 [info] Test "UNRELIABLE_TEST_2277_0022" succeeded.
2015-02-10 08:47:31.509915 [info] Test "ADDRESS_TEST_1234_0022" succeeded.
2015-02-10 08:47:31.510049 [info] Test "MIN_INITIAL_DELAY_TEST_1234_0022" succeeded.
2015-02-10 08:47:31.510354 [info] Test "MAX_INITIAL_DELAY_TEST_1234_0022" succeeded.
2015-02-10 08:47:31.510610 [info] Test "REPETITION_BASE_DELAY_TEST_1234_0022" succeeded.
2015-02-10 08:47:31.513978 [info] Test "REPETITION_MAX_TEST_1234_0022" succeeded.
2015-02-10 08:47:31.514177 [info] Test "CYCLIC_OFFER_DELAY_TEST_1234_0022" succeeded.
2015-02-10 08:47:31.514280 [info] Test "CYCLIC_REQUEST_DELAY_TEST_1234_0022" succeeded.
2015-02-10 08:47:31.514397 [info] Test "MIN_INITIAL_DELAY_TEST_1234_0023" succeeded.
2015-02-10 08:47:31.514618 [info] Test "MAX_INITIAL_DELAY_TEST_1234_0023" succeeded.
2015-02-10 08:47:31.514754 [info] Test "REPETITION_BASE_DELAY_TEST_1234_0023" succeeded.
2015-02-10 08:47:31.514901 [info] Test "REPETITION_MAX_TEST_1234_0023" succeeded.
2015-02-10 08:47:31.515052 [info] Test "CYCLIC_OFFER_DELAY_TEST_1234_0023" succeeded.
2015-02-10 08:47:31.515186 [info] Test "CYCLIC_REQUEST_DELAY_TEST_1234_0023" succeeded.
2015-02-10 08:47:31.515325 [info] Test "MIN_INITIAL_DELAY_TEST_2277_0022" succeeded.
2015-02-10 08:47:31.515395 [info] Test "MAX_INITIAL_DELAY_TEST_2277_0022" succeeded.
2015-02-10 08:47:31.515536 [info] Test "REPETITION_BASE_DELAY_TEST_2277_0022" succeeded.
2015-02-10 08:47:31.515691 [info] Test "REPETITION_MAX_TEST_2277_0022" succeeded.
2015-02-10 08:47:31.515834 [info] Test "CYCLIC_OFFER_DELAY_TEST_2277_0022" succeeded.
2015-02-10 08:47:31.515971 [info] Test "CYCLIC_REQUEST_DELAY_TEST_2277_0022" succeeded.
2015-02-10 08:47:31.516109 [info] Test "MIN_INITIAL_DELAY_TEST_2266_0022" succeeded.
2015-02-10 08:47:31.516279 [info] Test "MAX_INITIAL_DELAY_TEST_2266_0022" succeeded.
2015-02-10 08:47:31.516380 [info] Test "REPETITION_BASE_DELAY_TEST_2266_0022" succeeded.
2015-02-10 08:47:31.516512 [info] Test "REPETITION_MAX_TEST_2266_0022" succeeded.
2015-02-10 08:47:31.516610 [info] Test "CYCLIC_OFFER_DELAY_TEST_2266_0022" succeeded.
2015-02-10 08:47:31.516736 [info] Test "CYCLIC_REQUEST_DELAY_TEST_2266_0022" succeeded.
2015-02-10 08:47:31.516874 [info] Test "ADDRESS_TEST_4466_0321" succeeded.
2015-02-10 08:47:31.516974 [info] Test "SERVICE DISCOVERY PROTOCOL" succeeded.
2015-02-10 08:47:31.517106 [info] Test "SERVICE DISCOVERY PORT" succeeded.


Magic Cookies Test
------------------
To run the magic cookies test you need two devices on the same network. The network addresses within
the configuration files need to be adapted to match the devices addresses. 

To start the magic-cookies-test from the build-directory do:

HOST1: 
env VSOMEIP_CONFIGURATION_FILE=../config/vsomeip-magic-cookies-client.json \
VSOMEIP_APPLICATION_NAME=client-sample ./magic-cookies-test-client

HOST2: 
env VSOMEIP_CONFIGURATION_FILE=../config/vsomeip-magic-cookies-service.json \
VSOMEIP_APPLICATION_NAME=service-sample ./response-sample --tcp --static-routing

The expected result is an output like this on service side:

2015-02-10 08:42:07.317695 [info] Received a message with Client/Session [1343/0001]
2015-02-10 08:42:07.360105 [error] Detected Magic Cookie within message data. Resyncing.
2015-02-10 08:42:07.360298 [info] Received a message with Client/Session [1343/0003]
2015-02-10 08:42:07.360527 [error] Detected Magic Cookie within message data. Resyncing.
2015-02-10 08:42:07.360621 [error] Detected Magic Cookie within message data. Resyncing.
2015-02-10 08:42:07.360714 [info] Received a message with Client/Session [1343/0006]
2015-02-10 08:42:07.360850 [info] Received a message with Client/Session [1343/0007]
2015-02-10 08:42:07.361021 [error] Detected Magic Cookie within message data. Resyncing.
2015-02-10 08:42:07.361107 [error] Detected Magic Cookie within message data. Resyncing.
2015-02-10 08:42:07.361191 [error] Detected Magic Cookie within message data. Resyncing.
2015-02-10 08:42:07.361276 [info] Received a message with Client/Session [1343/000b]
2015-02-10 08:42:07.361434 [info] Received a message with Client/Session [1343/000c]
2015-02-10 08:42:07.361558 [info] Received a message with Client/Session [1343/000d]
2015-02-10 08:42:07.361672 [error] Detected Magic Cookie within message data. Resyncing.
2015-02-10 08:42:07.361761 [info] Received a message with Client/Session [1343/000f]

Header Factory Tests
--------------------

The following things are tested:
a) create request
    --> check  "Protocol Version" / "Message Type" / "Return Type" fields
b) create request, fill header, create response
    --> compare header fields of request & response
c) create notification
    --> check  "Protocol Version" / "Message Type" / "Return Type" fields
d) create message, fill header (service/instance/method/interface version/message type)
    --> send message 10 times
    --> receive message and check client id / session id

a) to c) are combined in one binary. d) is composed out of a client and service.

To start the header factory tests from the build directory do:

Automatic start from build directory:
ctest -V -R header_factory_test

Manual start from build directory:
cd test
./header_factory_test
# Start client and service separately
./header_factory_test_service_start.sh &
./header_factory_test_client_start.sh
# Alternatively start client and service with one script
./header_factory_test_send_receive_starter.sh

All tests should be marked as "passed".

Routing Tests
-------------

The following things are tested:
a) create a service instance
    - check that it is accessible from a local client but invisible for an external client
b) create a service instance, configure it to be externally visible
    - check that it is accessible from a local client and from a external client

a) and b) are composed out of a service each and one common client binary which is used
with different configuration files.

Automatic start from build directory:

ctest -V -R local_routing_test

A message will be shown when the external client should be started.

Manual start from build directory:
cd test
# First part with local client
# Start client and service with one script
./local_routing_test_starter.sh

# Alternatively start client and service separately
# Warning some checks are done within the *_starter.sh script.
# This should only be used for debugging
# Start the service
./local_routing_test_service_start.sh &
# Start the client
./local_routing_test_client_start.sh

# Second part with external client
# Start client and service with one script
./external_local_routing_test_starter.sh
# Start the external client from an external host when the message is displayed to start it
./external_local_routing_test_client_external_start.sh

# Alternatively start client and service separately
# Warning some checks are done within the *_starter.sh script.
# This should only be used for debugging
# Start the service
./external_local_routing_test_service_start.sh &
# Start the client
./local_routing_test_client_start.sh
# Start the external client from an external host after local client has finished
./external_local_routing_test_client_external_start.sh


All tests should be marked as "passed".

Payload Tests
-------------

The following things are tested:
a) create a local service
    - send messages with payloads of different size from a local client to the service
    - check that the messages are received correctly
    - measure the throughput
b) create a service instance, configure it to be externally visible
    - send messages with payloads of different size from a local client to the service
    - check that the messages are received correctly
    - measure the throughput
c) create a service instance, configure it to be externally visible
    - send messages with payloads of different size from an external client to the service
    - check that the messages are received correctly
    - measure the throughput
d) create a service instance, configure it to be externally visible
    - send messages with payloads of different size from a local client to the service
    - send messages with payloads of different size from an external client to the service
    - check that the messages are received correctly
    - measure the throughput

The tests a) to d) are composed out of a service and a client binary which are called
with different configuration files and parameters.

Automatic start from build directory:

ctest -V -R payload_test

A message will be shown when the external clients should be started.

Manual start from build directory:
cd test

# First part with local client
# start client and service with one script
./local_payload_test_starter.sh

# Alternatively start client and service separately
# Warning some checks are done within the *_starter.sh script.
# This should only be used for debugging
./local_payload_test_service_start.sh &
./local_payload_test_client_start.sh

# Second part with external visible service and local client
# start client and service with one script
./external_local_payload_test_client_local_starter.sh

# Alternatively start client and service separately
# Warning some checks are done within the *_starter.sh script.
# This should only be used for debugging
./external_local_payload_test_service_start.sh &
./external_local_payload_test_client_local_start.sh

# Third part with external visible service and external client
# start client and service with one script
./external_local_payload_test_client_external_starter.sh
# Start the external client from an external host if asked to
./external_local_payload_test_client_external_start.sh

# Alternatively start client and service separately
# Warning some checks are done within the *_starter.sh script.
# This should only be used for debugging
./external_local_payload_test_service_client_external_start.sh
# Start the external client from an external host
./external_local_payload_test_client_external_start.sh

# Fourth part with external visible service and local and external client
# start client and service with one script
./external_local_payload_test_client_local_and_external_starter.sh
# Start the external client from an external host if asked to
./external_local_payload_test_client_external_start.sh

# Alternatively start client and service separately
# Warning some checks are done within the *_starter.sh script.
# This should only be used for debugging
./external_local_payload_test_service_client_external_start.sh &
# Start the local client
VSOMEIP_APPLICATION_NAME=external_local_payload_test_client_local \
VSOMEIP_CONFIGURATION_FILE=external_local_payload_test_client_local.json \
./payload_test_client --dont-shutdown-service
# Start the external client after the local client is finished from an
# external host
./external_local_payload_test_client_external_start.sh

All tests should be marked as "passed".
