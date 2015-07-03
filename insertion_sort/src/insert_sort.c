#include "insert_sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

		memcpy(key, &data[i * esize], esize);
		j = i - 1;

		while (j >= 0 && compare(&data[j * esize], key)) {
			memcpy(&data[(j + 1) * esize], &data[j * esize], esize);
			j--;
		}

		memcpy(&data[(j + 1) * esize], key, esize);
	}

	free(key);

	return 0;
}
