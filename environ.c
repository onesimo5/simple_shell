#include "shell.h"

/**
 * _myenv - prints the current environment
 * @info: struct contain arguments. For maintaining
 * const function prototype.
 * Return: always 0.
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - gets value of environ variable.
 * @info: struct contains potent argumnets for maintaining
 * @name: environ var name.
 *
 * Return: value.
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - init's a new env var,or modifies existing one.
 * @info: struct contains potent arguments.used to maintain
 * constant functn prototype.
 * Return: always 0.
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect numb of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - deletes environ var.
 * @info: struct contains potent arguments,use maintain
 * const function prototype.
 * Return: always 0.
 */
int _myunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * populate_env_list - populates the env linked list.
 * @info: struct contains potent arguments,for maintaining
 * function prototype.
 * Return: always 0.
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t a;

	for (a = 0; environ[a]; a++)
		add_node_end(&node, environ[a], 0);
	info->env = node;
	return (0);
}
