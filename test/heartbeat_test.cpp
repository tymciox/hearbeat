#include <gtest/gtest.h>

extern "C"
{
#include "heartbeat.h"
}

TEST(HeartbeatTest, SignalIsLongerThen110)
{
    EXPECT_EQ(1, heartbeat_check());
}
