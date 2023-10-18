#include <stdio.h>
#include "threads/thread.h"
#include "devices/timer.h"
#include "tests/threads/tests.h"

// timer_delay() Testing
void sleeper_thread(void) {
    int64_t ticks_before_sleep = timer_ticks();
    int64_t sleep_duration = 100; // Sleep for 100 timer ticks (adjust as needed)

    printf("Thread %s sleeping for %lld ticks\n", thread_name(), sleep_duration);
    timer_delay(sleep_duration);

    int64_t ticks_after_sleep = timer_ticks();
    int64_t actual_sleep_duration = ticks_after_sleep - ticks_before_sleep;

    printf("Thread %s woke up after %lld ticks\n", thread_name(), actual_sleep_duration);

    // Check if the actual sleep duration matches the expected duration
    if (actual_sleep_duration >= sleep_duration) {
        pass();
    } else {
        fail("Thread did not sleep for the expected duration");
    }
}
