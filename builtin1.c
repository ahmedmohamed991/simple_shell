#include "shell.h"
/**
*_myhistory - displays the history list, one command by line
*@info: structer containing potential arguments
*Return: always 0
*/
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
*unset_alias - sets alias to string
*@info: parameter struct
*@str:the string alias
*
*Return: always 0 on success, 1 on error
*/
int unset_alias(info_t *info, char *str)
{
	int x;
	char *pointer, c;

	pointer = _strchr(str, '=');

	if (!pointer)
		return (1);
c = *pointer;
*pointer = 0;
x = delet_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info, str, -1)));
*pointer = c;
return (x);
}

/**
 *
 *set_alias - sets alias to string
 *@info: the info struct to set the alias for
 *@str: the alias string in the form "alias=value"
 *Retur: alwayes 0 on success, 1 on failure
*/
int set_alias(info_t *info, char *str)
{
char *pointer;
pointer = _strchr(str, '=');
if (!pointer)
return (1);
if (!*++pointer)
return (unset_alias(info, str));
unset_alias(info, str);
return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
*print_alias - prints an alias string
*@node: the alias node
*
*Return: alwayes 0 on success, 1 on error
*/
int print_alias(list_t *node)
{
	char *x = NULL, *pointer = NULL;

	if (node)
	{
	    pointer = _strchr(node->str, '=');

		for (x = node->str; a <= pointer; x++)
			_putchar(*x);
	    _putchar(" \ ");
	    _puts(pointer + 1);
	    _puts("\n");
		return (0);
	}
	return (1);
}

/**
*_myalias - mimics the alias builtin (man alias)
*@info: structure containing potential arguments.
*Return: always 0
*/
int _myalias(info_t *info)
{
	char *pointer = NULL;
	int x = 0;
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
	for (x = 1; info->argv[x]; x++)
	{
	    pointer = _strchr(info->argv[x], '=')
		if (pointer)
		set_alias(info, info->argv[x]);
		else
			print_alias(node_starts_with(info->alias, info->argv[x], '='));
	}
	return (0);
}
