#include "hash.h"


int hash_table_init(HASH * hash_table, int buckets, int (*h)(const void *key),
		int (*match)(const void *data1, const void *data2))
{
	hash_table->table = (LIST *)malloc(buckets * sizeof(LIST));

	if (hash_table->table == NULL)
		return -1;
	
	hash_size(hash_table) = 0;
	hash_table->buckets = buckets;
	hash_table->h = h;
	hash_table->match = match;
	
	return 0;
}

void hash_table_destory(HASH * hash_table)
{
	if (!(hash_isEmpty(hash_table)))
		return;

	free(hash_table->table);
	memset(hash_table, 0, sizeof(HASH));
	
	return;
}

int hash_table_insert(HASH * hash_table, void * data)
{
	int bucket;
	LIST *list;
	struct listElement *element;

	bucket = hash_table->h(data) % hash_table->buckets;	

	list = &(hash_table->table[bucket]);
	element = list_head(list);

	while (element != NULL) {
		if (hash_table->match(element->data, data) == 1)
			return 1;
		element = element->next;
	}

	list_add_next(list, data);
	hash_size(hash_table)++;

	return 0;
}

void * hash_table_remove(HASH * hash_table, void * data)
{
	int bucket;
	LIST *list;
	struct listElement *element;

	bucket = hash_table->h(data) % hash_table->buckets;	

	list = &(hash_table->table[bucket]);
	element = list_head(list);

	while (element != NULL) {
		if (hash_table->match(element->data, data) == 1) {
			hash_size(hash_table)--;
			return list_rm_element(list, element);
		}
		element = element->next;
	}

	return NULL;
}
