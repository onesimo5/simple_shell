#include "shell.h"

/**
 * get_environ - returns str array copy of environ
 * @info: Structure containing arguments
 * used to maintain the constant function prototype.
 * Return: Always 0 (Success).
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * _unsetenv - deletes an environment var.
 * @info: Structure containing arguments
 * used to maintain the function prototype.
 * @var: str env var property.
 * Return: 1 on delete or otherwise 0.
 */
int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t i = 0;
	char *q;

	if (!node || !var)
		return (0);

	while (node)
	{
		q = starts_with(node->str, var);
		if (q && *q == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), i);
			i = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->env_changed);
}

/**
 * _setenv - inputs a new environment var or alters an existing one.
 * @info: Structure containing arguments
 * used to maintain constant function prototype.
 * @var: str env var property.
 * @value: the str env var value.
 * Return: Always 0 (Success).
 */
int _setenv(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *q;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = info->env;
	while (node)
	{
		q = starts_with(node->str, var);
		if (q && *q == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}
