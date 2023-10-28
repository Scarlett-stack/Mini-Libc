// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>
#include <internal/types.h>
int truncate(const char *path, off_t length)
{
	//aceasi procedura
	if (length < 0)
	{
		errno = EINVAL;
		return -1;
	}
	int rax = syscall(76, path, length);
	errno = -rax;
	if (rax < 0)
		return -1;
	return rax;
}
