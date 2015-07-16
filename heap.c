#include "heap.h"

Heap*
new_heap(int length_max) {
    Heap* heap = malloc(sizeof(Heap));
    heap->length_max = length_max,
    heap->length = 0;
    heap->data = malloc(length_max * sizeof(data_t));
    return heap;
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
heap_insert(data_t element, Heap* heap) {

    // Check if valid call
    assert(heap->length < heap->length_max);

    // Add element as last child
    heap->data[heap->length++] = element;

    // heapify up
    int node = heap->length - 1;
    while (!is_root(node) && heap->data[parent(node)] > element) {
        heap->data[node] = heap->data[parent(node)];
        node = parent(node);
    }
    heap->data[node] = element;


}

data_t
heap_get_top(Heap* heap) {
    return heap->data[0];
}

void
heap_pop(Heap* heap) {

    // Check if valid call
    assert(heap->length > 0);

    // Replace the root with the last leaf
    heap->data[0] = heap->data[heap->length - 1];

    int node = 0;
    int value = heap->data[--heap->length];

    // While the node has children
    for (int min_child = left(node);
            left(node) < heap->length;
            node = min_child) {

        // Find the smaller child
        int min_child = left(node);
        if (right(node) < heap->length &&
            heap->data[right(node)] < heap->data[left(node)]) {
            min_child = right(node);
        }

        // If there's need, do a fake swap
        if (heap->data[min_child] < value) {
            heap->data[node] = heap->data[min_child];
        } else {
            break;
        }
    }

    // Complete the fake swaps
    heap->data[node] = value;
}





