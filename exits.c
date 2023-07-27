#include "shell.h"

/**
 **_strncpy - copying a str.
 *@dest:the dest str to be copied.
 *@src: the source str.
 *@n: the amount of charact's to be copied.
 *Return: the concatnatd str.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int a, j;
	char *s = dest;

	a = 0;
	while (src[a] != '\0' && a < n - 1)
	{
		dest[a] = src[a];
		a++;
	}
	if (a < n)
	{
		j = a;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strncat - Concatenates two str's.
 *@dest: 1st str.
 *@src: 2nd str.
 *@n: amount of bytes to use.
 *Return: concatd str.
 */
char *_strncat(char *dest, char *src, int n)
{
	int a, j;
	char *s = dest;

	a = 0;
	j = 0;
	while (dest[a] != '\0')
		a++;
	while (src[j] != '\0' && j < n)
	{
		dest[a] = src[j];
		a++;
		j++;
	}
	if (j < n)
		dest[a] = '\0';
	return (s);
}

/**
 **_strchr - locates char in a str.
 *@s: str to parsed.
 *@c: char to look fr.
 *Return: The pointr to memory area s.
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
