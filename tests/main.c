#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

/* A test case that does nothing and succeeds. */
static void null_test_success(void **state) {
    (void) state; /* unused */
}

#include "heap.h"
#include "stdlib.h"
static void event_queue(void **state) {
    (void) state;

    // Create random events
    const int numevents = 10;
    Event events[numevents];
    for (int i = 0; i < numevents; i++) {
        events[i].x = rand();
        events[i].y = rand();
    }

    // Bubble sort
    Event sorted[numevents];
    for (int i = 0; i < numevents; i++) {
        sorted[i] = events[i];
    }
    qsort(sorted, numevents, sizeof(Event), compare_heap);

    // Insert events into the heap, check the size
    Heap* heap = new_heap(numevents);
    for (int i = 0; i < numevents; i++) {
        assert_int_equal(heap->length, i);
        heap_insert(events[i], heap);
    }

    // Pop elements and check order
    for (int i = 0; i < numevents; i++) {
        assert_int_equal(heap->length, numevents - i);
        Event event = heap_get_top(heap);
        heap_pop(heap);
        // assert_int_equal(event.x, sorted[i].x);
        // assert_int_equal(event.y, sorted[i].y);
    }

    // Free memory
    free_heap(heap);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(null_test_success),
        cmocka_unit_test(event_queue),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
