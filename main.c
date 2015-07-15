#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "geometry.h"
#include "common.h"
#include "image.h"

typedef struct {
    int     numSites;
    Box     box;
    Site*   sites;
} Inputs;

void
read_inputs(Inputs* inputs) {

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
}

int
main (int argc, char* argv[]) {
    
    // Read inputs
    Inputs inputs;
    read_inputs(&inputs);

    // Create allocate and clear image
    Image image;
    image.channels = 3;
    image.width = inputs.box.xMax - inputs.box.xMin;
    image.height = inputs.box.yMax - inputs.box.yMin;
    image.rowstride = image.width * image.channels;
    image.pixels = malloc(image.width * image.height * image.channels * sizeof(int));
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            uchar* p = image.pixels + i * image.rowstride + j * image.channels;
            p[0] = 255;
            p[1] = 255;
            p[2] = 255;
        }
    }

    fprintf(stderr, "asd");
    print_image(&image);
    fprintf(stderr, "asdsad");

    return 0;
}
