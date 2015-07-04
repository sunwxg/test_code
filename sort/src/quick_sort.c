#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <alloca.h>

#define DATA(i) &data[(i) * esize]
#define SWAP_DATA(a, b)  \
	if (swap_data(a, b, esize))\
		return -1;
	

static int swap_data(void * a, void * b, int size)
{
	void *temp;

	if ((temp = alloca(size)) == NULL)
		return -1;

	memcpy(temp, a, size);
	memcpy(a, b, size);
	memcpy(b, temp, size);

	return 0;
}

static int compare_pivot(void *key1, void *key2)
{
	int *a = (int *)key1;
	int *b = (int *)key2;

	return *a > *b ? 1 : 0;
}

static int chose_pivot(int lo, int hi)
{
	int r[3];

	r[0] =  (rand() % (hi - lo + 1)) + lo;
	r[1] =  (rand() % (hi - lo + 1)) + lo;
	r[2] =  (rand() % (hi - lo + 1)) + lo;
	insert_sort(r, 3, sizeof(int), compare_pivot);
	return r[1];
}

int partition(void * array, int esize, int lo, int hi,
	int compare(void * key1, void * key2))
{
	char *data = array;
	void *pivot_value;
	int store_index;
	int pivot_index = chose_pivot(lo, hi);

	if ((pivot_value = alloca(esize)) == NULL)
		return -1;

	memcpy(pivot_value, DATA(pivot_index), esize);

	SWAP_DATA(DATA(pivot_index), DATA(hi));

	store_index = lo;
	for (int i = lo; i < hi; i++) {
		if (compare(pivot_value, DATA(i)) > 0) {
			SWAP_DATA(DATA(i), DATA(store_index));
			store_index++;
		}
	}
	
	SWAP_DATA(DATA(store_index), DATA(hi));

	return store_index;
}

int quick_sort(void * array, int esize, int lo, int hi,
	int compare(void * key1, void * key2))
{
	int p;

	if (lo < hi) {
		if ((p= partition(array, esize, lo, hi, compare)) < 0)
			return -1;
		quick_sort(array, esize, lo, p - 1, compare);
		quick_sort(array, esize, p + 1, hi, compare);
	}

	return 0;
}