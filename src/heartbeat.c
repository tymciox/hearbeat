#include "heartbeat.h"

static int signal_cnt = 0;

void heartbeat_init(void)
{
    signal_cnt = 0;
}

int heartbeat_check(void)
{
    if (signal_cnt < 12)
    {
        signal_cnt++;
    }
    else
    {
        return 0;
    }

    return 1;
}