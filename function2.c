#include "shell.h"
/**
*delet_node_at_index - delets node at given index
*@head: address of pointer to first node
*@index: index of node to delet
*Return: 1 on success, 0 on failure
*/
int delet_node_at_index(list_t **head, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int x = 0;

	if (!head || !*head)
		return (0);
if (!index)
{
	node = *head;
	*head = (*head)->next;
	free(node->str);
	return (1);
}
node = *head;
while (node)
{
	if (x == index)
	{
		prev_node->next = node->next;
		free(node->str);
		free(node);
		return (1);
	}
	x++;
	prev_node = node;
	node = node->next;
}
return (0);
}

/**
*get_node_index - gets the index of a node
*@head: pointer to list head
*@node: pointer to the node
*Return: index of node or -1
*/
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t x = 0;

	while (head)
	{
		if (head == node)
			return (x);
		head = head->next;
		x++;
	}
	return (-1);
}

/**
*_putchar - writes the character c to stdout
*@c: the character to print
*Return: on seccess 1.
*/
int _putchar(char c)
{
	static char buf[WRITE_BUF_SIZE];
	static int x;

	if (c == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(1, buf, x);
		x = 0;
	}
	if (c != BUF_FLUSH)
		buf[x++] = c;
return (1);
}

/**
*_puts - prints an input string
*@str: the string to be printed
*Return: nothing
*/
void _puts(char *str)
{
	int x = 0;

	if (!str)
		return;
while (str[x] != '\0')
{
	_putchar(str[x]);
	x++;
}
}

/**
*print_list_str - prints only the str element of a list_t linked list
*@h: pointer to first node
*Return: size of list
*/
size_t print_list_str(const list_t *h)
{
	size_t x = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		x++;
	}
	return (x);
}

/**
*_unsetenv - remove an environment variable
*@info: strcture containing potential arguments.
*@var: the string env var property
*Return: 1 on delete, 0 otherwise
*/
int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t x = 0;
	char *pointer;

	if (!node || !var)
		return (0);

while (node)
{
	pointer = starts_with(node->str, var);

	if (pointer && *pointer == '=')
	{
		info->env_changed = delet_node_at_index(&(info->env), x);
		x = 0;
		node = info->env;
		continue;
	}
	node = node->next;
	x++;
}
return (info->env_changed);
}
