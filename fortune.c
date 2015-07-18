#include "fortune.h"

typedef struct {
    Heap* event_queue;
} State;

static State* 
// Creates a state and fills the event queue
new_state(Inputs* inputs) {
    State* state = malloc(sizeof(State));
    state->event_queue = new_heap(100000);
    for (int i = 0; i < inputs->numSites; i++) {
        Event event = {
            .x = inputs->sites[i].x,
            .y = inputs->sites[i].y
        };
        heap_insert(event, state->event_queue);
    }
    return state;
}

static void 
clean_up(State* state) {
    free_heap(state->event_queue);
    free(state);
}

void
fortune(Inputs* inputs, Image* image) {
    State* state = new_state(inputs);

    clean_up(state);
}
