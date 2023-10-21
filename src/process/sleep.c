#include <time.h>
#include <unistd.h>
#include <internal/syscall.h>
#include <stddef.h>
int nanosleep(const struct timespec *t1, struct timespec *t2)
{
	return syscall(35, t1, t2);
}
unsigned int sleep(unsigned int seconds)
{
   struct timespec tv;
    tv.tv_sec = seconds;
    tv.tv_nsec = 0;
	if (nanosleep(&tv, &tv))
		return tv.tv_sec;
	return 0; 
}
