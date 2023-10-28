// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/*m-am obisnuit de la iocla
	sa scriu cu pointeri si nu cu []
	pornesc de la primul caracter din destination
	si il pun in iterator_String
	pana cand ajung la termiantor
	si pe ala il pun in afara while-ului ca altfel as
	ramana e fara \0
	 */
	char *iterator_string = destination;
	while (*source != '\0')
	{
		*iterator_string = *source;
		source++;
		iterator_string++;
	}
	*iterator_string = '\0';
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* copiez primele len chars din source
	la fel ca la strcpy doar ca ma duc pana in len
	 */
	char *iterator_string = destination;
	size_t i = 0;
	while (i <= len)
	{
		*iterator_string = *source;
		iterator_string++;
		source++;
		i++;
	}
	*iterator_string = '\0';

	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* ma duc pana la capatul destinatiei
	si de acolo incep sa adaug si celalat string */
	char *iterator_string = destination;
	while (*iterator_string)
	{
		iterator_string++;
	}
	while (*source)
	{
		*iterator_string = *source;
		source++;
		iterator_string++;
	}
	*iterator_string = '\0';
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* la fel ma duc pana la capatul destnatiei
	si adaug incepand de aoclo primele len chars din source */
	size_t i = 0;
	char *iterator_string = destination + strlen(destination);

	while (i < len)
	{
		*iterator_string = *source;
		source++;
		iterator_string++;
		i++;
	}
	*iterator_string = '\0';

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* ma duc in ameble stringuri
	simultan pana cand fir ajung pe terminator
	sau cand am gasit un char diferit
	Apoi verific pe care dintre cdt sa oprit
	si returnez 0 daca s-au oprit pe \0 ->sunt egale
	-1 daca dif de chars e mai mica ca 0
	si implicit 1 adica dif de chars e >0  */
	while (*str1 == *str2 && *str1 != '\0' && *str2 != '\0')
	{
		str1++;
		str2++;
	}
	if (*str1 == '\0' && *str2 == '\0')
		return 0;

	if (*str1 - *str2 < 0)
		return -1;
	return 1;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* la fel ca la strcmp dar mai am
	in while cdt de oprire pana la len */
	size_t i = len;
	while (*str1 == *str2 && *str1 != '\0' && *str2 != '\0' && i <= len)
	{
		str1++;
		str2++;
		i++;
	}
	if (*str1 - *str2 > 0)
		return 1;

	if (*str1 - *str2 < 0)
		return -1;
	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/*aici am vrut s afac cu for ca mam plictist de while
	verific ca nu sunt pe \0 si compar
	cu charul dat ca arg si returnez adresa
	altefl ies din for si nu lam gasit deci NULL */
	unsigned int i;
	for (i = 0; *(str + i) != '\0'; i++)
		if (*(str + i) == c)
			return (char*)(str + i);
	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* astea cu rr incep de la coada
	deci ma deplaez invers si ma opresc pe prima
	aparitie din capatul final
	adica scad end */
	char *end =(char*) (str + strlen(str));
	while (end != str)
	{
		if (*end == c)
			return end;
		end--;
	}
	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	/* aici verific subsecventele sa vad
	daca gasesc needle
	deci iau copii la fiecare si iau fiecare subsir de lungime alui needle
	din haystack
	daca ajung pe \0 la needle inseamna ca l-am gasit
	fac un cast la char * la adresa din haystack pt
	ca functia nu retunreza const char *
	altfel ma duc mai departe in haystack
	daca ies din while inseamna ca nu am gasit
	dau NULL
	 */
	char *haystack_copie;
	char *needle_copie;
	while (*haystack != '\0')
	{
		haystack_copie = (char *) haystack;
		needle_copie = (char *) needle;
		while (*needle_copie != '\0' && *haystack_copie == *needle_copie)
		{
			haystack_copie++;
			needle_copie++;
		}
		if (*needle_copie == '\0')
		{
			return (char *)haystack;
		}
		haystack++;
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* aici nu ma opresc pe prima aparitie
	ci pe ultima deci tot apelez strstr pana nu il mai gasesc
	pe needle si daca ii gasesc o aparitie continui cautarea de la acea
	adresa */
	char *iterator_string =(char *) haystack;
	char *ultimul = NULL;
	while (strstr(iterator_string, needle))
	{
		iterator_string = strstr(iterator_string, needle);
		ultimul = iterator_string;
		iterator_string++;
	}
	if (ultimul != NULL)
		return ultimul;
	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* aparent trb castate la char * argumentele
	efectiv copiez din src in dest
	char cu char */
	unsigned int i;
	char *destinatie_nou = (char *)destination;
	char *src_nou = (char *)source;
	for (i = 0; i < num; i++)
	{
		*(destinatie_nou + i) = *(src_nou + i);
	}
	return destinatie_nou;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* mai teoretic se declara un buffer intermediar de size num
	da nu imi merge asa.
	Asa ca problema ramane daca source e o adresa de inceput
	sau mai mica in acelasi string destination.
	 */

	char *destiatie_nou = (char *)destination;
	const char *src_nou = (const char *)source;
	if (destiatie_nou == src_nou)
	return destiatie_nou;
	// verific daca am overlapp , adica daca se suprapun
	// adica daca cumva dest > src si des < src + cat chr copiez
	// daca da le duc pe ambele adrese la capat
	// si copiez de la capete  in destinatie_nou charurile
	// altfel nu se suparpun si copiez normal
	if (destiatie_nou > src_nou && destiatie_nou < src_nou + num)
	{
		destiatie_nou += num;
		src_nou += num;
		while (num--)
		{
			*(--destiatie_nou) = *(--src_nou);
		}
	} else {
		while (num--)
		{
			*destiatie_nou++ = *src_nou++;
		}
	}
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* asta compara continutul de la doua adrese primii num bytes
	le fac cast si verific daca sunt diferite
	returnez dif altfel continui si daca ies din while
	inseamna ca sunt egali primi num bytes
	*/
	char *copie_ptr1 = (char *)ptr1;
	char *copie_ptr2 = (char *)ptr2;

	while (num > 0)
	{
		if (*(copie_ptr1) != *(copie_ptr2))
			return *copie_ptr1 - *copie_ptr2;
		num--;
		copie_ptr1++;
		copie_ptr2++;
	}
	return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	char *setter = (char *)source;
	char val = (char)value;
	unsigned int i;
	for (i = 0; i < num; i++)
		*(setter + i) = val;
	return source;
}
