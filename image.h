#ifndef VORONOI_IMAGE_H
#define VORONOI_IMAGE_H

#include <assert.h>
#include <stdlib.h>

#include <gtk/gtk.h>
#include <glib/gi18n.h>

#include "common.h"

typedef struct {
    int     width;
    int     height;
    int     channels;
    int     rowstride;
    uchar*    pixels;
} Image;

static const gboolean           HAS_ALPHA = FALSE;
static const int                BITS_PER_SAMPLE = 8;
static const int                N_CHANNELS = 3;
static const GdkColorspace      COLORSPACE = GDK_COLORSPACE_RGB; 

// Forward declarations
void print_image(Image*);

#endif // VORONOI_IMAGE_H
