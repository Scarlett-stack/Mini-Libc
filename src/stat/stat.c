// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <fcntl.h>
#include <errno.h>

int stat(const char *restrict path, struct stat *restrict buf)
{
	/* TODO: Implement stat(). */
	int rax = syscall(4,path,buf);
	if (rax < 0)
	{
		errno = -rax;
		return -1;
	}
	return rax;

}
