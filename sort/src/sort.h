#ifndef __INSERT_SORT
#define __INSERT_SORT

int insert_sort(void * array, int asize, int esize, \
	int compare(void * key1, void * key2));


int quick_sort(void * array, int esize, int lo, int hi,
	int compare(void * key1, void * key2));

#endif  /*__INSERT_SORT */
