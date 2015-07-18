#include "heap.h"

int compare_event(const void* a, const void* b) {
    if (((Event*)a)->x != ((Event*)b)->x) {
        return ((Event*)a)->x - ((Event*)b)->x;
    }
    return ((Event*)a)->y - ((Event*)b)->y;
}

Heap*
new_heap(int num_inserts) {
    Heap* heap = malloc(sizeof(Heap));
    heap->num_inserts = num_inserts,
    heap->length = 0;
    heap->buffer_pos = 0;
    heap->data = malloc(num_inserts * sizeof(Event*));
    heap->buffer = malloc(num_inserts * sizeof(Event));
    return heap;
}

void
free_heap(Heap* heap) {
    free(heap->data);
    free(heap->buffer);
    free(heap);
}

static inline int
left(int node) {
    return 2 * node + 1;
}

static inline int
right(int node) {
    return 2 * node + 2;
}

static inline int
parent(int node) {
    return (node - 1) / 2;
}

static inline int
less(int node1, int node2, Heap* heap) {
    return compare_event(heap->data[node1], heap->data[node2]) < 0;
}

static inline void
swap_nodes(int a, int b, Heap* heap) {
    Event* tmp = heap->data[a];
    heap->data[a] = heap->data[b];
    heap->data[b] = tmp;
}

void
heap_insert(Event event, Heap* heap) {

    // Check if valid call
    assert(heap->buffer_pos < heap->num_inserts);

    // Add event as last child
    heap->buffer[heap->buffer_pos++] = event;
    heap->data[heap->length++] = &heap->buffer[heap->buffer_pos - 1];

    // heapify up
    for (int node = heap->length - 1;
            node != 0 && less(node, parent(node), heap);
            node = parent(node)) {
        swap_nodes(node, parent(node), heap);
    }
}

Event
heap_get_top(Heap* heap) {
    return *(heap->data[0]);
}

void
heap_pop(Heap* heap) {

    // Check if valid call
    assert(heap->length > 0);

    // Replace the root with the last leaf and delete the root
    swap_nodes(0, heap->length - 1, heap);
    heap->length--;

    // Heapify down
    for (int node = 0, min_child;
            left(node) < heap->length;
            node = min_child) {

        min_child = left(node);
        if (right(node) < heap->length &&
            less(right(node), left(node), heap)) {
            min_child = right(node);
        }

        if (less(min_child, node, heap)) {
            swap_nodes(min_child, node, heap); 
        } else {
            break;
        }
    }
}

int
heap_condition_satisfied(Heap* heap) {
    int good = 1;
    for (int i = 0; i < heap->length; i++) {
        if (left(i) < heap->length && less(left(i), i, heap)) {
            good = 0;
        }
        if (right(i) < heap->length && less(right(i), i, heap)) {
            good = 0;
        }
    }
    return good;
}



