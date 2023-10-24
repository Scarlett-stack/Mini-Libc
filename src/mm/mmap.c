// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	/* TODO: Implement mmap(). */

	long rax = syscall(9, addr, length, prot, flags, fd, offset);
	// pune frt argumentele toate
	errno = (int)-rax;
	if (rax < 0)
	{
		return MAP_FAILED;
	}
	// habarnam ce iam schimbat da mere
	void *p = (void *)rax;
	return p;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	/* TODO: Implement mremap(). */
	long rax = syscall(25, old_address, old_size, new_size, flags);
	if (rax < 0)
		return MAP_FAILED;
	return (void *)rax;
}

int munmap(void *addr, size_t length)
{
	/* TODO: Implement munmap(). */
	int rax = syscall(11, addr, length);
	errno = -rax;
	if (rax < 0)
	{
		return -1;
	}
	return rax;
}
