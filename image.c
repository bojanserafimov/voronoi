#include "image.h"


GdkPixbuf*
get_pixbuf_from_image(Image* image) {
    // Initialize pixbuf
    // TODO: deallocate memory
    GdkPixbuf* pixbuf = gdk_pixbuf_new_from_data(
            image->pixels, // TODO: not guchar
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

 	gtk_init (NULL, NULL);

    // Set up the UI
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
