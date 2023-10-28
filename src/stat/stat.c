// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <fcntl.h>
#include <errno.h>

int stat(const char *restrict path, struct stat *restrict buf)
{
	//la fel ca fstat verif ce returneaza syscallul
	//setez errno si returnez -1 daca rax < 0
	//altfel returnez rax
	int rax = syscall(4, path, buf);
	if (rax < 0)
	{
		errno = -rax;
		return -1;
	}
	return rax;
}
