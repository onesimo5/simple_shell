#include "shell.h"

/**
 * _myhistory - shows history of the list,one command line by line,procedeeding
 *  with line numbers starting from 0.
 * @info: struct containing arguments,used to contain a function of a prototype.
 * Return: Always 0 (Success).
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - inputs alias to str.
 * @info: parameter structure.
 * @str: str alias.
 * Return: Always 0 (Success) and 1 on error.
 */
int unset_alias(info_t *info, char *str)
{
	char *q, z;
	int ret;

	q = _strchr(str, '=');
	if (!q)
		return (1);
	z = *q;
	*q = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*q = z;
	return (ret);
}

/**
 * set_alias - inputs the alias to a str.
 * @info: parameter structure.
 * @str: str alias.
 * Return: Always 0 (Success) and 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *q;

	q = _strchr(str, '=');
	if (!q)
		return (1);
	if (!*++q)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - Prints alias str.
 * @node: The alias node.
 * Return: Always 0 (Success) and 1 on error.
 */
int print_alias(list_t *node)
{
	char *q = NULL, *d = NULL;

	if (node)
	{
		q = _strchr(node->str, '=');
		for (d = node->str; d <= q; d++)
			_putchar(*d);
		_putchar('\'');
		_puts(q + 1);
		_puts("'\n"); 
		return (0);
	}
	return (1);
}

/**
 * _myalias - Copies alias builtin.
 * @info: struct containing the arguments,used to hold a function of the prototype.
 * Return: Always 0 (Success).
 */
int _myalias(info_t *info)
{
	int i = 0;
	char *q = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		q = _strchr(info->argv[i], '=');
		if (q)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
