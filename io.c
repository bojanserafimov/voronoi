#include "io.h"

Inputs*
read_inputs() {
    
    Inputs* inputs = malloc(sizeof(Inputs));
    ASSERT(scanf("%d", &inputs->numSites) == 1);
    ASSERT(scanf("%d %d %d %d", &inputs->box.xMin,
                                &inputs->box.xMax,
                                &inputs->box.yMin,
                                &inputs->box.yMax) == 4);
    inputs->sites = malloc(inputs->numSites * sizeof(Site));
    for (int i = 0; i < inputs->numSites; i++) {
        ASSERT(scanf("%lf %lf", &inputs->sites[i].x,
                                &inputs->sites[i].y) == 2);
    }
    return inputs;
}

void
free_inputs(Inputs* inputs) {
    free(inputs->sites);
    free(inputs);
}
