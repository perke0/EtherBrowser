#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <gtk/gtk.h>

class MainWindow {
public:
    MainWindow();
    ~MainWindow();
    void setup_ui(GtkWidget *window);
    void toggle_sidebar(bool show);
    gboolean on_mouse_motion(GtkWidget *widget, GdkEventMotion *event, gpointer data);
    gboolean on_key_press(GtkWidget *widget, GdkEventKey *event, gpointer data);
    void load_styles(const char *css_path);
    void execute_command(const gchar *command);
    void search_query(const gchar *query);

private:
    GtkWidget *main_box;
    GtkWidget *sidebar;
    GtkWidget *search_entry;
    GtkWidget *command_bar;
};

#endif // MAINWINDOW_H
