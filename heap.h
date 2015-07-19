#ifndef VORONOI_HEAP_C
#define VORONOI_HEAP_C

#include "common.h"
#include "stdlib.h"
#include "assert.h"
#include "stdio.h"

typedef enum {
    SITE_EVENT,
    CIRCLE_EVENT
} EventType;

typedef struct {
    double x;
    double y;
    EventType type;
} Event;

typedef struct {
    int length;
    int buffer_pos;
    int num_inserts;
    Event* buffer;
    Event** data;
} Heap;

Heap* new_heap(int num_inserts);
void free_heap(Heap* heap);
int compare_event(const void* a, const void* b);

void heap_insert(Event element, Heap* heap);
Event heap_get_top(Heap* heap);
void heap_pop(Heap* heap);
int heap_condition_satisfied(Heap* heap);

#endif // VORONOI_HEAP_C

