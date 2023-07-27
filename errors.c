#include "shell.h"

/**
 * _eputs - prints input string.
 * @str: the str to print.
 *
 * Return: nothing 0.
 */
void _eputs(char *str)
{
	int a = 0;

	if (!str)
		return;
	while (str[a] != '\0')
	{
		_eputchar(str[a]);
		a++;
	}
}

/**
 * _eputchar - writes char c to stderr.
 * @c: the charact to print.
 * Return: on success 1
 * On error, returned -1, and erno is set.
 */
int _eputchar(char c)
{
	static int a;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || a >= WRITE_BUF_SIZE)
	{
		write(2, buf, a);
		a = 0;
	}
	if (c != BUF_FLUSH)
		buf[a++] = c;
	return (1);
}

/**
 * _putfd - write character c to the given fd.
 * @c: the charact to print.
 * @fd: Fileescriptor to write
 *
 * Return: on success 1.
 * on error, returned -1, and erno is set well
 */
int _putfd(char c, int fd)
{
	static int a;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || a >= WRITE_BUF_SIZE)
	{
		write(fd, buf, a);
		a = 0;
	}
	if (c != BUF_FLUSH)
		buf[a++] = c;
	return (1);
}

/**
 * _putsfd - print input string
 * @str: the string to print
 * @fd: filedescriptor to write
 *
 * Return: numbs characters put
 */
int _putsfd(char *str, int fd)
{
	int a = 0;

	if (!str)
		return (0);
	while (*str)
	{
		a += _putfd(*str++, fd);
	}
	return (a);
}
