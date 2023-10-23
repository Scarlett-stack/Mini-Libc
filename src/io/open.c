// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>
#include <sys/stat.h>

int open(const char *filename, int flags, ...)
{
	/* TODO: Implement open system call. */

	int mod_deschidere;
	va_list argumente;
	int caz1 = 0;

	va_start(argumente, flags); // de unde incepe nr de arg var?
	if (flags & O_CREAT == 0)	// fis exista
	{
		// errno = ENOENT;
		return -1;
	}
	mod_deschidere = va_arg(argumente, int); // teoretic modul e int
	va_end(argumente);						 // inchid macroul

	int rax = syscall(2, filename, flags, mod_deschidere);
	errno = -rax; // sa moara bibi
	if (rax < 0)  // ceva e in neregula
	{
		return -1;
	}

	return rax;
}
//sursa de inpiratie : https://opensource.apple.com/source/Libc/Libc-583/sys/open.c.auto.html