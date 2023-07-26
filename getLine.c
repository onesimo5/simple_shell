#include "shell.h"

/**
 * input_buf - buffers any of chained cmd.
 * @info: the parameter structure.
 * @buf: the address of buffer.
 * @len: the address of len var.
 * Return: bytes to be read.
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t e = 0;
	size_t len_q = 0;

	if (!*len)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
		e = getline(buf, &len_q, stdin);
		e = _getline(info, buf, &len_q);

		if (e > 0)
		{
			if ((*buf)[e - 1] == '\n')
			{
				(*buf)[e - 1] = '\0';
				e--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			{
				*len = e;
				info->cmd_buf = buf;
			}
		}
	}
	return (e);
}

/**
 * get_input - gets line -minus newline.
 * @info: the parameter structure.
 * Return: bytes to be read.
 */
ssize_t get_input(info_t *info)
{
	static char *buf;
	static size_t i, j, len;
	ssize_t e = 0;
	char **buf_q = &(info->arg), *q;

	_putchar(BUF_FLUSH);
	e = input_buf(info, &buf, &len);
	if (e == -1)
		return (-1);
	if (len)
	{
		j = i;
		e = buf + i;
		check_chain(info, buf, &j, i, len);
		while (j < len)
		{
			if (is_chain(info, buf, &j))
				break;
			j++;
		}

		i = j + 1;
		if (i >= len)
		{
			i = len = 0;
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_q = q;
		return (_strlen(q));
	}
	*buf_q = buf;
	return (e);
}

/**
 * read_buf - Reads buffer.
 * @info: the parameter structure.
 * @buf: the Buffer.
 * @i: The size.
 * Return: e.
 */
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
	ssize_t e = 0;

	if (*i)
		return (0);
	r = read(info->readfd, buf, READ_BUF_SIZE);
	if (e >= 0)
		*i = e;
	return (e);
}

/**
 * _getline - gets next line of input from STDIN.
 * @info: the parameter structure.
 * @ptr: the address of the pointer to the buffer preallocated or NULL.
 * @length: the size of the preallocated ptr buffer, if not NULL.
 * Return: S.
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t i, len;
	size_t k;
	ssize_t e = 0, s = 0;
	char *q = NULL, *new_q = NULL, *z;

	q = *pointr;
	if (q && length)
		s = *length;
	if (i == len)
		i = len = 0;

	e = read_buf(info, buf, &len);
	if (e == -1 || (e == 0 && len == 0))
		return (-1);

	c = _strchr(buf + i, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : len;
	new_q = _realloc(p, s, s ? s + k : k + 1);
	if (!new_q)
		return (q ? free(q), -1 : -1);

	if (s)
		_strncat(new_q, buf + i, k - i);
	else
		_strncpy(new_q, buf + i, k - i + 1);

	s += k - i;
	i = k;
	p = new_q;

	if (length)
		*length = s;
	*pointr = q;
	return (o);
}

/**
 * sigintHandler - blocks ctrl C.
 * @sig_num: signal number.
 * Return: return to void.
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
