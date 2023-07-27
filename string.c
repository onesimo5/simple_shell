#include "shell.h"

/**
 * _strlen - return length of str.
 * @s: str whose length to check.
 * Return: int length of str.
 */

int _strlen(char *s)
{
	int a = 0;

	if (!s)
		return (0);

	while (*s++)
		a++;
	return (a);
}

/**
 * _strcmp - helps to perform lexicogarphic comparison of two strangs.
 * @s1: 1first strang.
 * @s2: 2second strang.
 * Return: -tive if s1 < s2, ptive if s1 > s2, zero if s1 == s2.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - check if needle starts with an haystack.
 * @haystack: strto search
 * @needle: substr to search for.
 * Return: adress of the next char of haystack.
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - concatenates two str.
 * @dest: dest buffer.
 * @src: source buffer.
 * Return: the pointer to dest buffer.
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
