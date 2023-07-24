#include "shell.h"

/**
 * bfree - frees pointer and NULLs address.
 * @ptr: the address of the pointer to release.
 *
 * Return: 1 if released or otherwise 0
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
