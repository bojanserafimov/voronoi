#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "geometry.h"
#include "common.h"
#include "image.h"
#include "io.h"
#include "fortune.h"


int
main (int argc, char* argv[]) {
    
    // Read inputs
    Inputs* inputs = read_inputs();

    // Create image
    Image* image = new_image(
            inputs->box.xMax - inputs->box.xMin,
            inputs->box.yMax - inputs->box.xMin);

    // Generate random colors
    Color colors[inputs->numSites];
    for (int i = 0; i < inputs->numSites; i++) {
        colors[i] = random_color(); 
    }

    // Bruteforce voronoi
    for (int i = inputs->box.xMin; i < inputs->box.xMax; i++) {
        for (int j = inputs->box.yMin; j < inputs->box.yMax; j++) {
            Point curr = { .x = i, .y = j };
            int nearest = 0;
            for (int k = 0; k < inputs->numSites; k++) {
                double old_dist = distance_squared(&curr, &inputs->sites[nearest]);
                double new_dist = distance_squared(&curr, &inputs->sites[k]);
                if (new_dist < old_dist) {
                    nearest = k;
                }
            }
            set_pixel(i, j, colors[nearest], image); 
        }
    }

    // Do line sweep
    fortune(inputs, image);
    print_image(image);

    // Free memory
    free_image(image);
    free_inputs(inputs);

    return 0;
}
