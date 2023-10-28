// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	// folosesc mmap ca sa aloc memorie
	// si adaug in lista in caz ca trb eliberat mai tarziu
	// verific si ce returneaza extras
	if (size == 0)
		return NULL;
	int verific_add;
	void *pointer_nou = NULL;
	pointer_nou = mmap(pointer_nou, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (pointer_nou == NULL)
		return NULL;
	verific_add = mem_list_add(pointer_nou, size);
	if (verific_add == -1)
		return NULL;
	return pointer_nou;

	// sursa inspiratie:
	// ChatGpt pt a intelege cum functioneaza malloc in spate
	// aici e o versiune simplificata
}

void *calloc(size_t nmemb, size_t size)
{
	// aici verific daca nmemb * size face overflow
	// daca nu face apelez malloc(nmeb*size)
	// si fac memset cu 0
	if (size > 0 && nmemb > -1 / size)
	{
		return NULL;
	}
	void *ptr = malloc(size * nmemb);
	if (ptr == NULL)
		return NULL;

	memset(ptr, 0, size * nmemb);
	return ptr;
	// sursa de inspiratie conditie overflow :
	// https://elixir.bootlin.com/musl/v1.2.4/source/src/malloc/calloc.c
}

void free(void *ptr)
{
	if (ptr == NULL)
		return;
	// nu fac cu while ca nu are sens si cumva
	// da passed si seg fault?? daca fac cu while
	// ceea ce oricum era dubios ca nu are sens sa sterg acelasi lucru
	// de mai multe ori
	// anyway ideea e ca verific daca exista acel ptr in lista
	// daca nu , ies
	// daca da il dezaloc cu munmap
	// si verific si ce returneaza munmap
	// daca e codul bun , il sterg din lista pe acel pointer
	struct mem_list *bloc_de_parcurs;
	int sters;
	bloc_de_parcurs = mem_list_find(ptr);
	if (bloc_de_parcurs == NULL)
		return;

	int gasit = munmap(bloc_de_parcurs->start, bloc_de_parcurs->len);
	if (gasit == -1)
		return;
	sters = mem_list_del(bloc_de_parcurs->start);
	if (sters == -1)
		return;
	return;
}

void *realloc(void *ptr, size_t size)
{
	// daca primesc NULL il inapoiez
	//  daca size e 0 e limbaj "subtil" pt free
	if (ptr == NULL)
		return NULL;
	if (size == 0)
	{
		free(ptr);
		return NULL;
	}
	// caut ptr in lista mem_list
	// nu exista -> nu am ce sa realloc
	// si daca e deja acelasi size in lista il returnez pe ala
	// altfel apelez mremap() cu size ca noua dimensiune
	// sterg din lista ca e ocupat
	// verific daca del returneaza < 0 ->ceva e prost->dau NULL
	// altfel dau newptr
	struct mem_list *bloc_gasit = mem_list_find(ptr);
	if (bloc_gasit == NULL)
		return NULL;

	if (bloc_gasit->len == size)
	{
		return bloc_gasit->start;
	}

	void *newptr = mremap(bloc_gasit->start, bloc_gasit->len, size, 0);
	int gone_girl = mem_list_del(newptr);
	if (gone_girl < 0)
		return NULL;

	return newptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	if (ptr == NULL)
		return NULL;
	// aici e important sa verif daca nmemb * size face overflow
	// am inteles ca mai intai verific daca nu inmultesc cu 0
	// adica nmemb sa nu fie 0
	// evit un eventual overflow daca nu inumltesc size *nmemb = (chestie)
	// de acea e mai chill sa verific daca size > -1 /nmemb ca sa evit (chestie)
	if (nmemb > 0 && size > -1 / nmemb)
	{
		return NULL;
	}

	void *nou_realloc_array_ptr = realloc(ptr, nmemb * size);
	return nou_realloc_array_ptr;
}
