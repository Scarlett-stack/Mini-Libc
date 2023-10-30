// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>
#include <sys/stat.h>

int open(const char *filename, int flags, ...)
{
	/*aici se procedeaza un pic altfel
	avand nr de paramterii variabil (in antet am ...)
	trb sa extrag mod_deschidere din restul paramterilor
	se foloseste macro-ul va_list
	care se initializaaza cu va_start, si se inchide cu va_end
	ii zic lui list de la ce arg incep paramterii cu nr var
	si extrag urm int care e si modul de deschidere
	*/
	int mod_deschidere;

	if (flags & O_CREAT) // fis exista
	{
		va_list argumente;						 // argumente = o lista tip va_list
		va_start(argumente, flags);				 // de unde incepe nr de arg var?
		mod_deschidere = va_arg(argumente, int); // teoretic modul e int
		va_end(argumente);						 // inchid macroul
	}
	int rax = syscall(2, filename, flags, mod_deschidere);
	errno = -rax;
	if (rax < 0) // ceva e in neregula
	{
		return -1;
	}

	return rax;
}
// sursa de inpiratie : https://opensource.apple.com/source/Libc/Libc-583/sys/open.c.auto.html
