// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int close(int fd)
{
	//se verif fd daca e valid
	//fac sys_close id fiind 3
	//verific rax
	if (fd < 0)
	{
		return -1;
	}
	int rax = syscall(3, fd); // sper sa fie syscallul close
	if (rax == -1)			  // merge e ok
	{
		return -1;
	}
	return 0;
}
