#include "heap.h"

int compare_event(const void* a, const void* b) {
    if (((Event*)a)->x != ((Event*)b)->x) {
        return ((Event*)a)->x - ((Event*)b)->x;
    }
    return ((Event*)a)->y - ((Event*)b)->y;
}

static inline int 
less(int a, int b, Heap* heap) {
    if (heap->data[heap->perm[a]].x < heap->data[heap->perm[b]].x) return 1;
    if (heap->data[heap->perm[a]].y < heap->data[heap->perm[b]].y) return 1;
    return 0;
}

static inline void
swap(int a, int b, Heap* heap) {
    int tmp = heap->perm[a];
    heap->perm[a] = heap->perm[b];
    heap->perm[b] = tmp;
}

Heap*
new_heap(int length_max) {
    Heap* heap = malloc(sizeof(Heap));
    heap->length_max = length_max,
    heap->length = 0;
    heap->data = malloc(length_max * sizeof(Event));
    heap->perm = malloc(length_max * sizeof(int));
    return heap;
}

void
free_heap(Heap* heap) {
    free(heap->data);
    free(heap->perm);
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
is_root(int node) {
    return node == 0;
}

void
heap_insert(Event event, Heap* heap) {

    // Check if valid call
    assert(heap->length < heap->length_max);

    // Add event as last child
    heap->data[heap->length] = event;
    heap->perm[heap->length] = heap->length;
    heap->length++;

    // heapify up
    int node = heap->length - 1;
    while (!is_root(node) && less(node, parent(node), heap)) {
        swap(node, parent(node), heap);
        node = parent(node);
    }
}

Event
heap_get_top(Heap* heap) {
    return heap->data[heap->perm[0]];
}

void
heap_pop(Heap* heap) {

    // Check if valid call
    assert(heap->length > 0);

    // TODO: lol removing is not that easy
    // actually I should use pointers instead of
    // this perm bullcrap

    // Replace the root with the last leaf and delete the root
    heap->data[0] = heap->data[heap->length - 1];
    heap->length--;

    // Heapify down
    for (int node = 0, min_child = left(node);
            left(node) < heap->length;
            node = min_child) {

        if (right(node) < heap->length &&
            less(right(node), left(node), heap)) {
            min_child = right(node);
        }

        if (less(min_child, node, heap)) {
            swap(min_child, node, heap); 
        } else {
            break;
        }
    }
}





