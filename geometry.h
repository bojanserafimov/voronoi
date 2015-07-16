#ifndef VORONOI_GEOMETRY_H
#define VORONOI_GEOMETRY_H

#include <stdlib.h>
#include <math.h>

#include "common.h"

static const int MAX_COLOR = 256;

typedef struct {
    double x;
    double y;
} Point, Site;

typedef struct {
    int xMin;
    int xMax;
    int yMin;
    int yMax;
} Box;

double distance_squared(const Point* a, const Point* b);

#endif // VORONOI_GEOMETRY_H
