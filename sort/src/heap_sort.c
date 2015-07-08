#include "sort_internal.h"

//  iParent     = floor((i-1) / 2)
//  iLeftChild  = 2*i + 1
//  iRightChild = 2*i + 2

static void shift_up(void * array, int asize, int esize,
	int compare(void * key1, void * key2))
{
	char *data = array;
	int i = asize - 1;
	int iParent = (i - 1) / 2;

	if (iParent < 0)
		return;

	if (compare(DATA(i), DATA(iParent)) > 0) {
		SWAP_DATA(DATA(i), DATA(iParent));
		shift_up(array, iParent + 1, esize, compare);
	}

	return;
	
}

static void heapify_up(void * array, int asize, int esize,
	int compare(void * key1, void * key2))
{
	int i = 2;

	while(i <= asize) {
		shift_up(array, i, esize, compare);
		i++;
	}
	return;
}


static void shift_down(void * array, int start, int end, int esize,
	int compare(void * key1, void * key2))
{
	char *data = array;
	int i = start;
	int iLeftChild = (2 * i) + 1;
	int iRightChild = (2 * i) + 2;

	if (iLeftChild > end) {
		return;
	} else if (compare(DATA(iLeftChild), DATA(i)) > 0) {
		SWAP_DATA(DATA(i), DATA(iLeftChild));
		shift_down(array, iLeftChild, end, esize, compare);
	}

	if (iRightChild > end) {
		return;
	} else if (compare(DATA(iRightChild), DATA(i)) > 0) {
		SWAP_DATA(DATA(i), DATA(iRightChild));
		shift_down(array, iRightChild, end, esize, compare);
			return;
	}

	return;
}

static void heapify_down(void * array, int asize, int esize,
	int compare(void * key1, void * key2))
{
	int start = (asize -2) / 2;

	while (start >= 0) {
		shift_down(array, start, asize - 1, esize, compare);
		start--;
	}
	return;
}


void heap_sort_d(void * array, int asize, int esize,
	int compare(void * key1, void * key2))
{
	char *data = array;
	int count = asize - 1;

	heapify_down(array, asize, esize, compare);

	while (count > 0) {
		SWAP_DATA(DATA(0), DATA(count));
		count--;
		shift_down(array, 0, count, esize, compare);
	}
	return;
}

void heap_sort_u(void * array, int asize, int esize,
	int compare(void * key1, void * key2))
{
	char *data = array;
	int count = asize - 1;

	heapify_up(array, asize, esize, compare);

	while (count > 0) {
		SWAP_DATA(DATA(0), DATA(count));
		count--;
		shift_down(array, 0, count, esize, compare);
	}
	return;
}
