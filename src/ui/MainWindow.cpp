#include "MainWindow.h"
#include <string>
#include <iostream>
#include <cstdlib>

MainWindow::MainWindow() : search_bar(nullptr), main_content(nullptr) {}

void MainWindow::setup_ui(GtkWidget *window) {
    // Create a vertical box layout
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // Main content (normal browser view)
    main_content = gtk_label_new("Welcome to EtherBrowser!\n   Press Ctrl + s for navibar");
    gtk_box_pack_start(GTK_BOX(vbox), main_content, TRUE, TRUE, 0);

    // Hidden search bar
    search_bar = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(search_bar), "Search or type a command...");
    gtk_box_pack_start(GTK_BOX(vbox), search_bar, FALSE, FALSE, 0);
    gtk_widget_hide(search_bar); // Hidden by default

    // Connect the "activate" signal of the search bar
    g_signal_connect(search_bar, "activate", G_CALLBACK(+[](GtkWidget *widget, gpointer data) {
        MainWindow *self = static_cast<MainWindow *>(data);
        self->on_search_entry_activate(widget);
    }), this);

    // Connect key press and release events
    g_signal_connect(window, "key-press-event", G_CALLBACK(MainWindow::on_key_press), this);
    g_signal_connect(window, "key-release-event", G_CALLBACK(MainWindow::on_key_release), this);
}

gboolean MainWindow::on_key_press(GtkWidget *widget, GdkEventKey *event, gpointer data) {
    MainWindow *self = static_cast<MainWindow *>(data);
    if (event->keyval == GDK_KEY_Control_L || event->keyval == GDK_KEY_Control_R) {
        self->ctrl_pressed = true; // Track that Ctrl is pressed
    }
    if (self->ctrl_pressed && event->keyval == GDK_KEY_s) {
        self->toggle_search_bar();
        return TRUE; // Stop further propagation of the event
    }
    return FALSE; // Allow other handlers to process the event
}

gboolean MainWindow::on_key_release(GtkWidget *widget, GdkEventKey *event, gpointer data) {
    MainWindow *self = static_cast<MainWindow *>(data);
    if (event->keyval == GDK_KEY_Control_L || event->keyval == GDK_KEY_Control_R) {
        self->ctrl_pressed = false; // Reset the Ctrl press state
    }
    return FALSE;
}

void MainWindow::toggle_search_bar() {
    if (gtk_widget_get_visible(search_bar)) {
        gtk_widget_hide(search_bar);
        gtk_widget_grab_focus(main_content); // Refocus on main content
    } else {
        gtk_widget_show(search_bar);
        gtk_widget_grab_focus(search_bar); // Focus the search bar
    }
}

void MainWindow::on_search_entry_activate(GtkWidget *widget) {
    const char *input_text = gtk_entry_get_text(GTK_ENTRY(widget));
    if (!input_text || input_text[0] == '\0') {
        gtk_widget_hide(search_bar);
        return;
    }

    if (input_text[0] == ':') {
        std::string command(input_text + 1); // Strip the leading ':'
        std::cout << "Executing command: " << command << std::endl;
    } else {
        std::string query(input_text);
        std::string search_url = "https://www.google.com/search?q=" + query;
        std::cout << "Searching for: " << search_url << std::endl;

        // Open the search URL in the default browser
        std::string open_command = "xdg-open \"" + search_url + "\"";
        std::system(open_command.c_str());
    }

    gtk_entry_set_text(GTK_ENTRY(widget), ""); // Clear the entry
    gtk_widget_hide(search_bar); // Hide the search bar after use
}


