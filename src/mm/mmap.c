// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	//aici e treba de cast la ce trb
	//long la adresa si int la rax ca sa calculez errno
	long rax = syscall(9, addr, length, prot, flags, fd, offset);
	// nu mergea ca nu puneam toate args :[
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
	//pretty much the same
	long rax = syscall(25, old_address, old_size, new_size, flags);
	if (rax < 0)
		return MAP_FAILED;
	return (void *)rax;
}

int munmap(void *addr, size_t length)
{
	//aici am errno
	int rax = syscall(11, addr, length);
	errno = -rax;
	if (rax < 0)
	{
		return -1;
	}
	return rax;
}
