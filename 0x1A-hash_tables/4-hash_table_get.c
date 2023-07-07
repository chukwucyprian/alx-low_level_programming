#include "hash_tables.h"

/**
 * hash_table_get - Retrieves the value associated with a key in the hash table
 * @ht: The hash table
 * @key: The key
 *
 * Return: The value associated with the key, or NULL if key couldn't be found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *temp = NULL;
	unsigned long int index = 0;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	/* Calculate the index where the key should be found */
	index = key_index((const unsigned char *)key, ht->size);

	/* Traverse the linked list at the index to find the key */
	temp = ht->array[index];
	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
			return (temp->value);
		temp = temp->next;
	}

	return (NULL);
}

