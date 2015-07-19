#include "fortune.h"

typedef struct {
    Heap* event_queue;
    double sweep_line_x;
} State;

static State* 
// Creates a state and fills the event queue
new_state(Inputs* inputs) {

    // Initialize state
    State* state = malloc(sizeof(State));

    // Fill event queue
    state->event_queue = new_heap(100000);
    for (int i = 0; i < inputs->numSites; i++) {
        Event event = {
            .x = inputs->sites[i].x,
            .y = inputs->sites[i].y,
            .type = SITE_EVENT
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

static void 
process_site_event(Event* event, State* state) {
    
}

static void
process_circle_event(Event* event, State* state) {

}

void
fortune(Inputs* inputs, Image* image) {
    State* state = new_state(inputs);
    
    while (state->event_queue->length > 0) {
        
        // Get next event
        Event event = heap_get_top(state->event_queue);
        heap_pop(state->event_queue);

        // Process event
        state->sweep_line_x = event.x;
        switch (event.type) {
            case SITE_EVENT:
                process_site_event(&event, state);
                break;
            case CIRCLE_EVENT:
                process_circle_event(&event, state);
                break;
        }
    }

    clean_up(state);
}
