#include "sort_internal.h"

#define COPY_DATA(d, s) copy_data(d, s, b, a, esize)
#define LeftNotEmpty (i0 <= iMiddle)
#define RightEmpty (i1 > iEnd)
#define i0_SmallThan_i1 (compare(DATA(i1), DATA(i0)) > 0)

static void copy_data(int dest, int src, void *darray, void *sarray, int esize)
{
	char *destArray = darray;
	char *srcArray = sarray;

	memcpy(&destArray[dest * esize], &srcArray[src * esize], esize);
}

static void copy_array(void *dest, void *src, int iBegin, int iEnd, int esize)
{
	for (int i = iBegin; i <= iEnd; i++) {
		copy_data(i, i, dest, src, esize);
	}
}

static void merge(void * a, int iBegin, int iMiddle, int iEnd,
	void * b, int esize, int compare(void * key1, void * key2))
{
	char *data = a;
	int i0 = iBegin;
	int i1 = iMiddle + 1;

	for (int j = iBegin; j <= iEnd; j++) {

		if (LeftNotEmpty && (RightEmpty || i0_SmallThan_i1)) {
			COPY_DATA(j, i0);
			i0++;
		} else {
			COPY_DATA(j, i1);
			i1++;
		}
	}

	return;
}

static void m_split_sort_t2d(void * a, int iBegin, int iEnd, void * b, int esize,
	int compare(void * key1, void * key2))
{
	int iMiddle;

	if ( (iEnd - iBegin) < 1)
		return;
	
	iMiddle = (iBegin + iEnd - 1) / 2;

	//left half
	m_split_sort_t2d(a, iBegin, iMiddle, b, esize, compare);

	//right half
	m_split_sort_t2d(a, iMiddle + 1, iEnd, b, esize, compare);

	merge(a, iBegin, iMiddle, iEnd, b, esize, compare);

	copy_array(a, b, iBegin, iEnd, esize);

	return;
}

int merge_sort_t2d(void * array, int asize, int esize,
	int compare(void * key1, void * key2))
{
	void *b = malloc(asize * esize);
	
	if (b == NULL)
		return -1;

	m_split_sort_t2d(array, 0, asize - 1, b, esize, compare);

	free(b);
	
	return 0;
}

static int min(int a, int b)
{
	return a < b ? a : b;
}

static void m_split_sort_d2t(void * a, void * b, int asize, int esize,
	int compare(void * key1, void * key2))
{
	int iBegin;
	int iMiddle;
	int iEnd;
	int width;

	//width = 2 4 8 16
	for (width = 1; width < asize; width = width * 2) {
		for (int i = 0; i < asize; i = i + 2 * width) {
			iBegin = i;
			iMiddle = min(i + width - 1, asize - 1);
			iEnd = min(i + 2 * width - 1, asize - 1);

			merge(a, iBegin, iMiddle, iEnd, b, esize, compare);
			copy_array(a, b, iBegin, iEnd, esize);
		}
	}
}

int merge_sort_d2t(void * array, int asize, int esize,
	int compare(void * key1, void * key2))
{
	void *b = malloc(asize * esize);
	
	if (b == NULL)
		return -1;

	m_split_sort_d2t(array, b, asize, esize, compare);

	free(b);
	
	return 0;
}
