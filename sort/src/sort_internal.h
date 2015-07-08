#ifndef __SORT_INTERNAL
#define __SORT_INTERNAl

#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <alloca.h>

#define DATA(i) &data[(i) * esize]
#define SWAP_DATA(a, b)  swap_data(a, b, esize)

void swap_data(void * a, void * b, int size);
void print_array(int *array, int asize);


#endif  /*__SORT_INTERNAL */
