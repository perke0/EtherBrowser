#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <gtk/gtk.h>

class MainWindow {
public:
    MainWindow();
    ~MainWindow();
    
    // Declare the static wrapper method
    static void on_search_entry_activate_static(GtkWidget *widget, gpointer data);

    void setup_ui(GtkWidget *window);

private:
    void on_search_entry_activate(GtkWidget *widget);

    GtkWidget *search_entry;
};

#endif // MAINWINDOW_H





