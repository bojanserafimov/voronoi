#include "image.h"


static uchar*
get_uchar_pointer(Image* image, int x, int y) {
    return image-> pixbuf+ x * image->rowstride + y * image->channels;
}

Color
random_color() {
    Color c;
    c.r = rand() % 256;
    c.g = rand() % 256;
    c.b = rand() % 256;
    return c;
}

static GdkPixbuf*
get_pixbuf_from_image(Image* image) {
    GdkPixbuf* pixbuf = gdk_pixbuf_new_from_data(
            image->pixbuf,
            GDK_COLORSPACE_RGB,
            HAS_ALPHA,
            BITS_PER_SAMPLE,
            image->width,
            image->height,
            image->rowstride,
            NULL,
            NULL);
    return pixbuf;
}


void 
print_image(Image* image) {

    // Set up the UI
 	gtk_init (NULL, NULL);
	GtkWidget* window   = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	GtkWidget* box      = gtk_box_new (GTK_ORIENTATION_VERTICAL, 5);
    GdkPixbuf* pixbuf   = get_pixbuf_from_image(image);
    GtkWidget* widget   = gtk_image_new_from_pixbuf(pixbuf);

    // Widget relations
	gtk_box_pack_start (GTK_BOX (box), widget, TRUE, TRUE, 0);
	gtk_container_add (GTK_CONTAINER (window), box);

    // Connect signals
	g_signal_connect (window, "destroy",            G_CALLBACK (gtk_main_quit), NULL);
    g_signal_connect (window, "key_press_event",    G_CALLBACK (gtk_main_quit),  NULL);

	gtk_widget_show_all (window);
	gtk_main ();
}

Image*
new_image(int width, int height) {
    Image* image = malloc(sizeof(Image));
    init_image(width, height, image);
    return image;
}

void
init_image(int width, int height, Image* image) {

    // Initialize with default properties
    image->width = width;
    image->height = height;
    image->channels = N_CHANNELS;
    image->rowstride = image->width * image->channels;
    image->pixbuf = malloc(image->width * image->height * 
            image->channels * sizeof(int));

    // Fill black
    for (int i = 0; i < image->width; i++) {
        for (int j = 0; j < image->height; j++) {
            uchar* p = get_uchar_pointer(image, i, j);
            p[0] = BLACK;
            p[1] = BLACK;
            p[2] = BLACK;
        }
    }
}

void
free_image(Image* image) {
    delete_image(image);
    free(image);
}

void
delete_image(Image* image) {
    free(image->pixbuf);
}

void 
set_pixel(int x, int y, Color color, Image* image) {
    uchar* p = get_uchar_pointer(image, x, y);
    p[0] = color.r;
    p[1] = color.g;
    p[2] = color.b;
}
