// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	if (size == 0)
		return NULL;
	struct mem_list *bloc_din_find;
	int extras;
	while (bloc_din_find = mem_list_find(NULL) != NULL)
	{
		if (bloc_din_find->len >= size)
		{
			extras = mem_list_del(bloc_din_find->start);
			if (extras == -1)
			{
				return NULL;
			}

			return bloc_din_find->start;
		}
		bloc_din_find = mem_list_find(bloc_din_find->start);
	}
	void *aloc_bloc_nou = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	// se lasa kernelul sa decida adresa lui bloc nou dand NULL ca parametru
	int adaugat = mem_list_add(aloc_bloc_nou, size);

	return aloc_bloc_nou;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	void *ptr = malloc(size * nmemb);
	if (ptr == NULL)
		return NULL;
	memmove(ptr, ptr, size * nmemb);
	return ptr;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	if (ptr == NULL)
		return;
	int gasit = 0;
	struct mem_list *bloc_de_parcurs, *bloc_de_sters;
	while (bloc_de_sters = mem_list_find(ptr) != NULL)
	{ // bloc_de_parcurs->start = NULL;
		int gasit = munmap(bloc_de_sters->start, bloc_de_sters->len);
		if (gasit != -1)
			return;
		bloc_de_sters = mem_list_find(bloc_de_sters->start);
	}

	return;
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	return NULL;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	return NULL;
}
