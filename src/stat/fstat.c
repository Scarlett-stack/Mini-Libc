// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <errno.h>

int fstat(int fd, struct stat *st)
{
	/* TODO: Implement fstat(). */
	if (fd < 0)
	{
		errno = EBADF;
		return -1;
	}
	int rax = syscall(5, fd, st);
	if (rax < 0)
	{
		errno = -rax;
		return -1;
	}
	return rax;
}
