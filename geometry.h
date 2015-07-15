#ifndef VORONOI_GEOMETRY_H
#define VORONOI_GEOMETRY_H


typedef struct {
    double x;
    double y;
} Point, Vector, Site;

typedef struct {
    int xMin;
    int xMax;
    int yMin;
    int yMax;
} Box;

#endif // VORONOI_GEOMETRY_H
