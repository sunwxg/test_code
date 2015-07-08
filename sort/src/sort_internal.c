#include "sort_internal.h"

void swap_data(void * a, void * b, int size)
{
	void *temp = alloca(size);

	memcpy(temp, a, size);
	memcpy(a, b, size);
	memcpy(b, temp, size);

	return;
}

void print_array(int *array, int asize)
{
	printf("\n");
	for (int i = 0; i < asize; i++) {
		printf("%d\t", *(array + i));
	}
	printf("\n");
}
