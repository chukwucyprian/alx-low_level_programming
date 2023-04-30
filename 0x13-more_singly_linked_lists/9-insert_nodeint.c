#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node in a linked list,
 * at a given position
 * @head: pointer to the first node in the list
 * @idx: index where the new node is added
 * @n: data to insert in the new node
 *
 * Return: pointer to the new node, or NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i;
	listint_t *vew;
	listint_t *tmp = *head;

	vew = malloc(sizeof(listint_t));
	if (!vew || !head)
		return (NULL);

	vew->n = n;
	vew->next = NULL;

	if (idx == 0)
	{
		vew->next = *head;
		*head = vew;
		return (vew);
	}

	for (i = 0; tmp && i < idx; i++)
	{
		if (i == idx - 1)
		{
			vew->next = tmp->next;
			tmp->next = vew;
			return (vew);
		}
		else
			tmp = tmp->next;
	}

	return (NULL);
}


