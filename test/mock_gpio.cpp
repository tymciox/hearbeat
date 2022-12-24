#include "mock_gpio.h"

static MockGPIO *_mock = nullptr;

void gpio_mock_init(MockGPIO *mock)
{
    _mock = mock;
}

extern "C"
{
    gpio_state_t heartbeat_pin_get(void)
    {
        if (_mock != nullptr) 
        {
            return _mock->heartbeat_pin_get();
        }
        else
        {
            return GPIO_UNKNOW;
        }
    }
}