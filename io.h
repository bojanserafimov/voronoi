#ifndef VORONOI_IO_H
#define VORONOI_IO_H

#include "common.h"
#include "geometry.h"
#include "assert.h"
#include "stdio.h"

typedef struct {
    int     numSites;
    Box     box;
    Site*   sites;
} Inputs;

Inputs* read_inputs();
void free_inputs(Inputs* inputs);

#endif // VORONOI_IO_H
