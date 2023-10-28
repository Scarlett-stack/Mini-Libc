// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <errno.h>

int fstat(int fd, struct stat *st)
{
	//verific fd sa fie valid
	//apelez syscallul lui fstat
	//verfic ce returneaza syscallul
	// dau lui errno = -rax daca rax < 0, adica e cv prost
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
	//sursa de inspiratie-documentatie:
	//https://linux.die.net/man/2/fstat
}
