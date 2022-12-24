#include <gmock/gmock.h>

extern "C"
{
#include "gpio.h"
}

class MockGPIO
{
    public:
    MOCK_METHOD(gpio_state_t, heartbeat_pin_get, ());
};

void gpio_mock_init(MockGPIO *mock);