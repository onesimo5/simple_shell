#include "shell.h"
/**
 * interactive - will return true, if the shell is in interactive mode.
 * @info: structure address.
 *
 * Return: 1 if it is in interactive mode else 0.
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - will check if the character is a delimeter or not.
 * @c: character to check.
 * @delim: delimeter str.
 * Return: 1 if it is true
 * or 0, if it is false 
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *_isalpha - will check for any alphabetic char.
 *@c: character to insert.
 *Return: 1 if c is alphabetic
 or 0 otherwise.
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
/**
 *_atoi - changes a string into an int.
 *@s: string to change.
 *Return: 0 if it has no numbers in the string, otherwise change the number.
 */

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
