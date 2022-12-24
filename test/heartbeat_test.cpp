#include <gtest/gtest.h>
#include "mock_gpio.h"

extern "C"
{
#include "heartbeat.h"
}

using ::testing::Return;
using ::testing::InSequence;

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

    for (int i=0; i<12; i++)
    {
        heartbeat_check();
    }
    EXPECT_EQ(1, heartbeat_check_alarm_state());
}

TEST_F(HeartbeatTest, ThreeToogleSignal)
{
    MockGPIO mock;

    InSequence s;
    EXPECT_CALL(mock, heartbeat_pin_get())
        .Times(10)
        .WillRepeatedly(Return(GPIO_LOW));
    EXPECT_CALL(mock, heartbeat_pin_get())
        .Times(10)
        .WillRepeatedly(Return(GPIO_HIGH));
    EXPECT_CALL(mock, heartbeat_pin_get())
        .WillRepeatedly(Return(GPIO_LOW));

    gpio_mock_init(&mock);

    for (int i=0; i<30; i++)
    {
        heartbeat_check();
    }
    EXPECT_EQ(0, heartbeat_check_alarm_state());
}
