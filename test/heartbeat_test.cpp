#include <gtest/gtest.h>
#include "mock_gpio.h"

extern "C"
{
#include "heartbeat.h"
}

using ::testing::Return;

TEST(HeartbeatTest, SignalIsLongerThen110)
{
    MockGPIO mock;

    EXPECT_CALL(mock, heartbeat_pin_get())
        .WillRepeatedly(Return(GPIO_LOW));
    gpio_mock_init(&mock);

    for (int i=0; i<12; i++)
    {
        EXPECT_EQ(1, heartbeat_check());
    }
}
