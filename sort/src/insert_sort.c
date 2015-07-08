#include "sort_internal.h"


int insert_sort(void * array, int asize, int esize, \
	int compare(void * key1, void * key2))
{
	int i,
	    j;
	char *data = array;
	void *key;

	if ((key = alloca(esize)) == NULL)
		return -1;
	
	for (i = 1; i < asize; i++) {

		memcpy(key, DATA(i), esize);
		j = i - 1;

		// data(j-1) < data(j)=key < data(j+1)
		while (j >= 0 && (compare(DATA(j), key) > 0)) {
			memcpy(DATA(j + 1), DATA(j), esize);
			j--;
		}

		memcpy(DATA(j + 1), key, esize);
	}

	return 0;
}
