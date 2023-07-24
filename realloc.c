#include "shell.h"

/**
 **_memset - fills memory a const byte.
 *@s: pointer to  mem area.
 *@b: the byte to fill *s with
 *@n: amount of bytes that are going to receive filling.
 *Return: pointer to memory location.
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * ffree - frees str of strings.
 * @pp: The str of strings.
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - reallocates the block of memory.
 * @ptr: the pointer to the previous malloc block.
 * @old_size: byte size of the old block.
 * @new_size: byte size of the new block.
 *
 * Return: pointer to the old block name.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
