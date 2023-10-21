#ifndef _TIME_H
#define _TIME_H

//nu pune asta : #include <sys/types.h> -> conflict de dependinte
struct timespec {
    long tv_sec;      
    long   tv_nsec;     
};

int nanosleep(const struct timespec *req, struct timespec *rem);

#endif /* _TIME_H */
/*
Cod inspirat din https://pubs.opengroup.org/onlinepubs/7908799/xsh/time.h.html
*/