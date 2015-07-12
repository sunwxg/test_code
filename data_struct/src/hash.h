#ifndef __HASH_H
#define __HASH_H 1

#include "list.h"
#include "string.h"

struct Hash_table {
	int buckets;
	int size;
	int (*match)(const void *data1, const void *data2);
	int (*h)(const void *key);
	LIST *table;
};

typedef struct Hash_table HASH;

int hash_table_init(HASH * hash_table, int buckets, int (*h)(const void *key),
		int (*match)(const void *data1, const void *data2));
void hash_table_destory(HASH * hash_table);
int hash_table_insert(HASH * hash_table, void * data);
void * hash_table_remove(HASH * hash_table, void * data);

#define hash_size(h) (h)->size
#define hash_isEmpty(h) (!(h)->size)

#endif /* __HASH_H */
