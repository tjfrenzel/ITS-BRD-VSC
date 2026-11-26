#include "timer.h"
#include "time.h"
#include <stdint.h>


uint64_t get_timestamp64(Time *time){
    time->timestamp_old = time->timestamp_new;
    time->timestamp_new = getTimeStamp();
    time->timestamp_64 += (time->timestamp_new - time->timestamp_old);
    return time->timestamp_64;
}

void init_time(Time *time){
    time->timestamp_old = 0;
    time->timestamp_new = 0;
    time->timestamp_64 = 0;
    time->timestamp_diff = 0;
}