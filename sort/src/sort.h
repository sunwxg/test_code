#ifndef __SORT
#define __SORT

int insert_sort(void * array, int asize, int esize,
	int compare(void * key1, void * key2));

int quick_sort(void * array, int esize, int lo, int hi,
	int compare(void * key1, void * key2));

int heap_sort_u(void * array, int asize, int esize,
	int compare(void * key1, void * key2));

int heap_sort_d(void * array, int asize, int esize,
	int compare(void * key1, void * key2));

int merge_sort_t2d(void * array, int asize, int esize,
	int compare(void * key1, void * key2));
#endif  /*__SORT */
