#ifndef __SORT_INTERNAL
#define __SORT_INTERNAl

#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <alloca.h>

#define DATA(i) &data[(i) * esize]
#define SWAP_DATA(a, b)  \
	if (swap_data(a, b, esize))\
		return -1;

int swap_data(void * a, void * b, int size);


#endif  /*__SORT_INTERNAL */
