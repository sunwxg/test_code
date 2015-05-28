#include <event.h>
#include <stdio.h>

struct event ev_event;
struct timeval tv;

void time_cb(int fd, short event, void *argc)
{
    printf("timer wakeup\n");
    event_add(&ev_event, &tv); // reschedule timer
}

int main()
{
    struct event_base *base = event_init();
    tv.tv_sec = 3; // 10s period
    tv.tv_usec = 0;
    evtimer_set(&ev_event, time_cb, NULL);
    event_add(&ev_event, &tv);
    event_base_dispatch(base);

    return 0;
}
