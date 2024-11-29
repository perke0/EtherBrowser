#include <gtk/gtk.h>
#include "ui/MainWindow.h"

static void on_activate(GtkApplication *app, gpointer user_data) {
    MainWindow *mainWindow = static_cast<MainWindow*>(user_data);
    mainWindow->setup_ui(GTK_WIDGET(gtk_application_window_new(app)));
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkApplication *app = gtk_application_new("org.example.EtherBrowser", G_APPLICATION_DEFAULT_FLAGS);

    MainWindow mainWindow;

    // Connect the "activate" signal to the on_activate function
    g_signal_connect(app, "activate", G_CALLBACK(on_activate), &mainWindow);

    int status = g_application_run(G_APPLICATION(app), argc, argv);

    g_object_unref(app);
    return status;
}



