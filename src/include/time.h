#ifndef _TIME_H
#define _TIME_H

// nu pune asta : #include <sys/types.h> -> conflict de headere
struct timespec
{
    long tv_sec;
    long tv_nsec;
};

int nanosleep(const struct timespec *req, struct timespec *rem);

#endif
/*
Cod inspirat de/din https://pubs.opengroup.org/onlinepubs/7908799/xsh/time.h.html
cu mentiunea ca tv_sec e de tipul time_t dar eu l-am pus long pt usurinta :]
*/
