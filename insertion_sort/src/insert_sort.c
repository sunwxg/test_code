#include "insert_sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATA(i) &data[(i) * esize]

int insert_sort(void * array, int asize, int esize, \
	int compare(void * key1, void * key2))
{
	int i,
	    j;
	char *data = array;
	void *key;

	if ((key = malloc(esize)) == NULL)
		return -1;
	
	for (i = 1; i < asize; i++) {

		memcpy(key, DATA(i), esize);
		j = i - 1;

		while (j >= 0 && compare(DATA(j), key)) {
			memcpy(DATA(j + 1), DATA(j), esize);
			j--;
		}

		memcpy(DATA(j + 1), key, esize);
	}

	free(key);

	return 0;
}
