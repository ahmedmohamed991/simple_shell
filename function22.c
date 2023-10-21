#include "shell.h"
/**
 * print_list_str - prints only the str element of a list_t linked list
 * @h: pointer to first node
 * Return: size of list
 */
size_t print_list_str(const list_t *h)
{
	size_t x = 0;

	while (h)
{
	puts(h->str ? h->str : "(nil)");
	_eputs("\n");
	h = h->next;
	x++;
}
return (x);
}
