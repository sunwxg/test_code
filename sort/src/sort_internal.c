#include "sort_internal.h"

int swap_data(void * a, void * b, int size)
{
	void *temp;

	if ((temp = alloca(size)) == NULL)
		return -1;

	memcpy(temp, a, size);
	memcpy(a, b, size);
	memcpy(b, temp, size);

	return 0;
}

void print_array(int *array, int asize)
{
	printf("\n");
	for (int i = 0; i < asize; i++) {
		printf("%d\t", *(array + i));
	}
	printf("\n");
}
