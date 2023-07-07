#ifndef HASH_TABLES_H
#define HASH_TABLES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structures */

/**
 * struct hash_node_s - Node of a hash table
 *
 * @key: The key, string
 * The key is unique in the HashTable
 * @value: The value corresponding to a key
 * @next: A pointer to the next node of the List
 */
typedef struct hash_node_s
{
char *key;
char *value;
struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - Hash table data structure
 *
 * @size: The size of the array
 * @array: An array of size @size
 * Each cell of this array is a pointer to the first node of a linked list,
 * because we want our HashTable to use a Chaining collision handling
 */
typedef struct hash_table_s
{
unsigned long int size;
hash_node_t **array;
} hash_table_t;

/* Function Prototypes */

hash_table_t *hash_table_create(unsigned long int size);
unsigned long int hash_djb2(const unsigned char *str);
unsigned long int key_index(const unsigned char *key, unsigned long int size);
int hash_table_set(hash_table_t *ht, const char *key, const char *value);
char *hash_table_get(const hash_table_t *ht, const char *key);
void hash_table_print(const hash_table_t *ht);
void hash_table_delete(hash_table_t *ht);

/* Structures */

/**
 * struct shash_node_s - Sorted hash table node
 * @key: The key string
 * @value: The value string
 * @next: Pointer to the next node
 * @sprev: Pointer to the previous node in the sorted list
 * @snext: Pointer to the next node in the sorted list
 *
 * Description: Each node in the sorted hash table has a key/value pair,
 * along with pointers to the next node in the hash table and the previous
 * and next nodes in the sorted list.
 */
typedef struct shash_node_s
{
char *key;
char *value;
struct shash_node_s *next;
struct shash_node_s *sprev;
struct shash_node_s *snext;
} shash_node_t;

/**
 * struct shash_table_s - Sorted hash table
 * @size: The size of the hash table array
 * @array: Array of pointers to shash_node_t nodes
 * @shead: Pointer to the head of the sorted list
 * @stail: Pointer to the tail of the sorted list
 *
 * Description: The sorted hash table structure contains the size of the hash
 * table array, an array of pointers to nodes, and pointers to the head and tail
 * of the sorted list.
 */
typedef struct shash_table_s
{
unsigned long int size;
shash_node_t **array;
shash_node_t *shead;
shash_node_t *stail;
} shash_table_t;

/* Function Prototypes */

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);



#endif /* HASH_TABLES_H */

