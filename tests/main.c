#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

/* A test case that does nothing and succeeds. */
static void null_test_success(void **state) {
    (void) state; /* unused */
}

#include "heap.h"
static void event_queue(void **state) {
    (void) state;

    Heap* heap = new_heap(10);
    free_heap(heap);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(null_test_success),
        cmocka_unit_test(event_queue),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
