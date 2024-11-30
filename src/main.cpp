#include <gtk/gtk.h>
#include "ui/MainWindow.h"

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    MainWindow mainWindow;
    mainWindow.setup_ui(window);

    gtk_window_set_title(GTK_WINDOW(window), "EtherBrowser");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}



