#include <unabto/unabto_external_environment.h>

nabto_stamp_t nabtoGetStamp() {
    struct timespec res;
#ifdef __MACH__
    clock_serv_t cclock;
    mach_timespec_t mts;
    host_get_clock_service(mach_host_self(), CALENDAR_CLOCK, &cclock);
    clock_get_time(cclock, &mts);
    mach_port_deallocate(mach_task_self(), cclock);
    res.tv_sec = mts.tv_sec;
    res.tv_nsec = mts.tv_nsec;
#elif defined(CLOCK_MONOTONIC)
    clock_gettime(CLOCK_MONOTONIC, &res);
#else
    clock_gettime(CLOCK_REALTIME, &res);
#endif
    return res.tv_sec*1000 + (res.tv_nsec/1000000);
}

bool nabtoIsStampPassed(nabto_stamp_t* stamp) {
    nabto_stamp_t now = nabtoGetStamp();
    return *stamp <= now;
}

nabto_stamp_diff_t nabtoStampDiff(nabto_stamp_t * newest, nabto_stamp_t * oldest) {
    return newest - oldest;
}

int nabtoStampDiff2ms(nabto_stamp_diff_t diff) {
    return (int) diff;
}

