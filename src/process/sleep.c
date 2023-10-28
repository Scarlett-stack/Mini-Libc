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
	struct timespec timp;
	timp.tv_sec = seconds;
	timp.tv_nsec = 0;
	if (nanosleep(&timp, &timp))
		return timp.tv_sec;
	return 0;
}
//
// sursa de inspiratie :
// https://stackoverflow.com/questions/7684359/how-to-use-nanosleep-in-c-what-are-tim-tv-sec-and-tim-tv-nsec
