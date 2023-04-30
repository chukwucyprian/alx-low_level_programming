#include "lists.h"

/**
 * print_listint - prints all the required elements of a linked list
 * @h: linked list of type listint_t to print
 *
 * Return: number of nodes in the linked list
 */
size_t print_listint(const listint_t *h)
{
	size_t numb = 0;

	while (h)
	{
		printf("%d\n", h->n);
		numb++;
		h = h->next;
	}

	return (numb);
}

