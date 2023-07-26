#include "shell.h"

/**
 * _myhistory - shows history of the list,one command line by line,procedeeding
 *  with line numbers starting from 0.
 * @info: struct containing arguments
 * used to contain a function of a prototype.
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
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
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
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
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
<<<<<<< HEAD
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
=======
	char *q = NULL, *v = NULL;

	if (node)
	{
		q = _strchr(node->str, '=');
		for (v = node->str; a <= q; v++)
			_putchar(*a);
		_putchar('\'');
		_puts(q + 1);
>>>>>>> efe21a8a5b747ea9accdc0fdc5c9558b4caf45c0
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - Copies alias builtin.
 * @info: struct containing the arguments
 * used to hold a function of the prototype.
 * Return: Always 0 (Success).
 */
int _myalias(info_t *info)
{
<<<<<<< HEAD
	int i = 0;
	char *p = NULL;
=======
	int z = 0;
	char *q = NULL;
>>>>>>> efe21a8a5b747ea9accdc0fdc5c9558b4caf45c0
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
	for (z = 1; info->argv[i]; z++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
