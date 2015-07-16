#ifndef VORONOI_HEAP_C
#define VORONOI_HEAP_C

#include "common.h"
#include "stdlib.h"
#include "assert.h"
#include "stdio.h"

typedef int data_t;

typedef struct {
    int length;
    int length_max;
    data_t* data;
} Heap;

Heap* new_heap(int length_max);
void heap_insert(data_t element, Heap* heap);
data_t heap_get_top(Heap* heap);
void heap_pop(Heap* heap);

#endif // VORONOI_HEAP_C

