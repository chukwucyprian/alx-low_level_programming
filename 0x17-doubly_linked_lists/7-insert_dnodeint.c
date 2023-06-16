#include "lists.h"

/**
 * insert_dnodeint_at_index -Inserts a new node at a
 given position in a dlistint_t list.
 * @h: Pointer to a pointer to the head of the list.
 * @idx: Index where the new node should be inserted.
 * @n: The value to be stored in the new node.
 *
 * Return: The address of the new node, or NULL if it failed.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
dlistint_t *new_node = malloc(sizeof(dlistint_t));
dlistint_t *current = *h;
unsigned int count = 0;
if (h == NULL)
return (NULL);
if (new_node == NULL)
return (NULL);
new_node->n = n;
if (idx == 0)
{new_node->prev = NULL;
new_node->next = *h;
if (*h != NULL)
(*h)->prev = new_node;
*h = new_node;
return (new_node);
}
while (current != NULL && count < idx)
{current = current->next;
count++;
}
if (current == NULL && count == idx)
{new_node->prev = *h;
new_node->next = NULL;
(*h)->next = new_node;
return (new_node);
}
else if (current != NULL && count == idx)
{new_node->prev = current->prev;
new_node->next = current;
current->prev->next = new_node;
current->prev = new_node;
return (new_node);
}
else
{
free(new_node);
return (NULL);
}
}
