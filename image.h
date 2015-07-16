#ifndef VORONOI_IMAGE_H
#define VORONOI_IMAGE_H

#include <assert.h>
#include <stdlib.h>

#include <gtk/gtk.h>
#include <glib/gi18n.h>

#include "common.h"

// Internal constants
static const gboolean           HAS_ALPHA           = FALSE;
static const int                BITS_PER_SAMPLE     = 8;
static const int                N_CHANNELS          = 3;
static const GdkColorspace      COLORSPACE          = GDK_COLORSPACE_RGB; 
static const uchar              BLACK               = 0;

typedef struct {
    int r;
    int g;
    int b;
} Color;

typedef struct {
    int     width;
    int     height;
    int     channels;
    int     rowstride;
    uchar*  pixbuf;
} Image;

// Standard struct methods
Image*  new_image       (int width, int height);
void    init_image      (int width, int height, Image* image);
void    free_image      (Image* image);
void    delete_image    (Image* image);

void    print_image     (Image* image);
void    set_pixel       (int x, int y, Color color, Image* image);
Color   random_color    ();

#endif // VORONOI_IMAGE_H
