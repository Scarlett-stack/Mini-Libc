// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>
#include <internal/types.h>
int ftruncate(int fd, off_t length)
{
	//verific paramtrii sa fie valizi
	//altfel fac syscallul
	//si returnez valoarea daca e buna
	//altfel -1
	if (length < 0)
	{
		errno = EINVAL;
		return -1;
	}
	if (fd < 0)
	{
		errno = EBADF;
		return -1;
	}
	int rax = syscall(77, fd, length);
	if (rax < 0)
	{
		errno = -rax;
		return -1;
	}
	return rax;
}
