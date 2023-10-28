// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>
#include <internal/types.h>

off_t lseek(int fd, off_t offset, int whence)
{
	//la fel verific, syscall, return
	if (fd < 0)
	{
		errno = EBADF;
		return -1;
	}
	if (whence != SEEK_CUR && whence != SEEK_END && whence != SEEK_SET)
	{
		errno = EINVAL;
		return -1;
	}
	if (offset < 0)
	{
		errno = EINVAL;
		return -1;
	}

	off_t dupa_lseek;
	dupa_lseek = syscall(8, fd, offset, whence);

	// errno = -dupa_lseek;
	if (dupa_lseek == -1)
	{
		return -1;
	}
	return dupa_lseek;
}
