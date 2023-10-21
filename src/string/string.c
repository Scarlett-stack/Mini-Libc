// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */

	char *iterator = destination;
	while (*source != '\0')
	{
		*iterator = *source;
		source++;
		iterator++;
	}
	*iterator = '\0';
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	char *iterator = destination;
	int i = 0;
	while (i <= len)
	{
		*iterator = *source;
		iterator++;
		source++;
		i++;
	}
	*iterator = '\0';

	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	char *iterator = destination;
	while (*iterator)
	{
		iterator++;
	}
	while (*source)
	{
		*iterator = *source;
		source++;
		iterator++;
	}
	*iterator = '\0';
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	int i = 0;
	char *iterator = destination + strlen(destination);

	while (i < len)
	{
		*iterator = *source;
		source++;
		iterator++;
		i++;
	}
	*iterator = '\0';

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	// for (; *str1 != '\0' && *str2 !='\0' && *str1 == *str2; str1++, str2++);
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
	/* TODO: Implement strncmp(). */
	unsigned int i = len;
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
	/* TODO: Implement strchr(). */
	unsigned int i;
	for (i = 0; *(str + i) != '\0'; i++)
		if (*(str + i) == c)
			return str + i;
	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	char *end = str + strlen(str);
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
	/* TODO: Implement strstr(). */
	char *it1;
	char *it2;
	while (*haystack != '\0')
	{
		it1 = haystack;
		it2 = needle;
		while (*it2 != '\0' && *it1 == *it2)
		{
			it1++;
			it2++;
		}
		if (*it2 == '\0')
		{
			return (char *)haystack;
		}
		haystack++;
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	char *iterator = haystack;
	char *ultimul = NULL;
	while (strstr(iterator, needle))
	{
		iterator = strstr(iterator, needle);
		ultimul = iterator;
		iterator++;
	}
	if (ultimul != NULL)
		return ultimul;
	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	unsigned int i;
	char *dest = (char *)destination;
	char *src = (char *)source;
	for (i = 0; i < num; i++)
	{
		*(dest + i) = *(src + i);
	}
	// return destination;
}

void *memmove(void *destination, const void *source, size_t num) // 2 dau fail??? doamne nu ma lasa!
{
	/* TODO: Implement memmove(). */

	char *dest = (char *)destination;
	const char *src = (const char *)source;

	if (dest > src && dest < src + num)
	{
		dest += num;
		src += num;
		while (num--)
		{
			*(--dest) = *(--src);
		}
	} else {
		while (num--)
		{
			*dest++ = *src++;
		}
	}
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
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
