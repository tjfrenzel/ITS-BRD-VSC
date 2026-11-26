#ifndef TIME_H
#define TIME_H

#include <stdint.h>

typedef struct{
    uint32_t timestamp_old;
    uint32_t timestamp_new;
    uint64_t timestamp_64;
    uint32_t timestamp_diff;
} Time;

uint64_t get_timestamp64(Time *time);
void init_time(Time *time);

#endif