#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <gtk/gtk.h>

class MainWindow {
public:
    MainWindow();
    void setup_ui(GtkWidget *window);

private:
    GtkWidget *search_bar;      // The search/command bar
    GtkWidget *main_content;    // The main browser content
    bool ctrl_pressed = false;  // Tracks if Ctrl is pressed

    // Event handlers
    static gboolean on_key_press(GtkWidget *widget, GdkEventKey *event, gpointer data);
    static gboolean on_key_release(GtkWidget *widget, GdkEventKey *event, gpointer data);
    void toggle_search_bar();   // Toggles the visibility of the search bar
    void on_search_entry_activate(GtkWidget *widget); // Handles search/command bar input
};

#endif // MAINWINDOW_H