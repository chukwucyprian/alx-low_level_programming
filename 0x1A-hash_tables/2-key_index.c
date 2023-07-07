#include "hash_tables.h"
/**
 * key_index - Retrieves the index for a given key in the hash table array
 * @key: The key
 * @size: The size of the array
 *
 * Return: The index for the key/value pair
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash_value = hash_djb2(key);
	unsigned long int index = hash_value % size;

	return (index);
}

