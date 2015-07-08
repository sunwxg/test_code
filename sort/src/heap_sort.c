#include "sort_internal.h"

//  iParent     = floor((i-1) / 2)
//  iLeftChild  = 2*i + 1
//  iRightChild = 2*i + 2

static int shift_up(void * array, int asize, int esize,
	int compare(void * key1, void * key2))
{
	char *data = array;
	int i = asize - 1;
	int iParent = (i - 1) / 2;

	if (iParent < 0)
		return 0;

	if (compare(DATA(i), DATA(iParent)) > 0) {
		SWAP_DATA(DATA(i), DATA(iParent));
		shift_up(array, iParent + 1, esize, compare);
	}

	return 0;
	
}

static int heapify_up(void * array, int asize, int esize,
	int compare(void * key1, void * key2))
{
	int i = 2;

	while(i <= asize) {
		if (shift_up(array, i, esize, compare) < 0)
			return -1;
		i++;
	}
	return 0;
}


static int shift_down(void * array, int start, int end, int esize,
	int compare(void * key1, void * key2))
{
	char *data = array;
	int i = start;
	int iLeftChild = (2 * i) + 1;
	int iRightChild = (2 * i) + 2;

	if (iLeftChild > end) {
		return 0;
	} else if (compare(DATA(iLeftChild), DATA(i)) > 0) {
		SWAP_DATA(DATA(i), DATA(iLeftChild));
		if (shift_down(array, iLeftChild, end, esize, compare) < 0)
			return -1;
	}

	if (iRightChild > end) {
		return 0;
	} else if (compare(DATA(iRightChild), DATA(i)) > 0) {
		SWAP_DATA(DATA(i), DATA(iRightChild));
		if (shift_down(array, iRightChild, end, esize, compare) < 0)
			return -1;
	}

	return 0;
}

static int heapify_down(void * array, int asize, int esize,
	int compare(void * key1, void * key2))
{
	int start = (asize -2) / 2;

	while (start >= 0) {
		if (shift_down(array, start, asize - 1, esize, compare) < 0)
			return -1;
		start--;
	}
	return 0;
}


int heap_sort_d(void * array, int asize, int esize,
	int compare(void * key1, void * key2))
{
	char *data = array;
	int count = asize - 1;

	heapify_down(array, asize, esize, compare);

	while (count > 0) {
		SWAP_DATA(DATA(0), DATA(count));
		count--;
		if (shift_down(array, 0, count, esize, compare) < 0)
			return -1;
	}
	return 0;
}

int heap_sort_u(void * array, int asize, int esize,
	int compare(void * key1, void * key2))
{
	char *data = array;
	int count = asize - 1;

	if (heapify_up(array, asize, esize, compare) < 0)
		return -1;

	while (count > 0) {
		SWAP_DATA(DATA(0), DATA(count));
		count--;
		if (shift_down(array, 0, count, esize, compare) < 0)
			return -1;
	}
	return 0;
}
