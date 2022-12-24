#include <gtest/gtest.h>
#include "mock_gpio.h"

extern "C"
{
#include "heartbeat.h"
}

using ::testing::Return;

class HeartbeatTest : public testing::Test
{
    protected:

    void SetUp() override
    {
        heartbeat_init();
    }

    void TearDown() override
    {

    }
};

TEST_F(HeartbeatTest, SignalIsLongerThen110)
{
    MockGPIO mock;

    EXPECT_CALL(mock, heartbeat_pin_get())
        .WillRepeatedly(Return(GPIO_LOW));
    gpio_mock_init(&mock);

    for (int i=0; i<11; i++)
    {
        heartbeat_check();
    }
    EXPECT_EQ(1, heartbeat_check());
}
