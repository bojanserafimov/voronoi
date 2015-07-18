#ifndef VORONOI_HEAP_C
#define VORONOI_HEAP_C

#include "common.h"
#include "stdlib.h"
#include "assert.h"
#include "stdio.h"

typedef struct {
    int x;
    int y;
} Event;

typedef struct {
    int length;
    int length_max;
    Event* data;
    int* perm;
} Heap;

Heap* new_heap(int length_max);
void free_heap(Heap* heap);
int compare_event(const void* a, const void* b);

void heap_insert(Event element, Heap* heap);
Event heap_get_top(Heap* heap);
void heap_pop(Heap* heap);

#endif // VORONOI_HEAP_C

