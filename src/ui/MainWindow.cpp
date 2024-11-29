#include "MainWindow.h"
#include <gtk/gtk.h>

MainWindow::MainWindow() {
    // Constructor logic (if any)
}

MainWindow::~MainWindow() {
    // Destructor logic (if any)
}

void MainWindow::setup_ui(GtkWidget *window) {
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    search_entry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(search_entry), "Search...");

    gtk_box_pack_start(GTK_BOX(box), search_entry, TRUE, TRUE, 0);
    gtk_container_add(GTK_CONTAINER(window), box);

    // Connect the signal with the static method
    g_signal_connect(search_entry, "activate", 
        G_CALLBACK(MainWindow::on_search_entry_activate_static), 
        this);

    gtk_widget_show_all(window);
}

void MainWindow::on_search_entry_activate(GtkWidget *widget) {
    const gchar *text = gtk_entry_get_text(GTK_ENTRY(widget));
    if (text && *text) {
        // Execute the search or command
        g_print("Search or Command: %s\n", text);
    }
}

// Static method to wrap the non-static method call
void MainWindow::on_search_entry_activate_static(GtkWidget *widget, gpointer data) {
    MainWindow *windowInstance = static_cast<MainWindow*>(data);  // Convert 'data' to MainWindow pointer
    windowInstance->on_search_entry_activate(widget);  // Call the instance method
}


