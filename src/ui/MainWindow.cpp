#include "../../include/MainWindow.h"
#include <gtk/gtk.h>
#include <string>

static gboolean on_mouse_motion_wrapper(GtkWidget *widget, GdkEventMotion *event, gpointer data);
static gboolean on_key_press_wrapper(GtkWidget *widget, GdkEventKey *event, gpointer data);

MainWindow::MainWindow() : sidebar(nullptr), main_box(nullptr), search_entry(nullptr), command_bar(nullptr) {}
MainWindow::~MainWindow() {}

void MainWindow::setup_ui(GtkWidget *window) {
    load_styles("resources/styles/dark.qss");

    main_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_container_add(GTK_CONTAINER(window), main_box);

    sidebar = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_widget_set_size_request(sidebar, 200, -1); // Set the width of the sidebar
    gtk_widget_set_name(sidebar, "sidebar");

    gtk_box_pack_start(GTK_BOX(main_box), sidebar, FALSE, FALSE, 0);

    GtkWidget *label1 = gtk_label_new("Tab 1: Youtube");
    GtkWidget *label2 = gtk_label_new("Tab 2: Twitter");
    gtk_box_pack_start(GTK_BOX(sidebar), label1, FALSE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(sidebar), label2, FALSE, FALSE, 5);

    gtk_widget_hide(sidebar);

    GtkWidget *main_content = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_box_pack_start(GTK_BOX(main_box), main_content, TRUE, TRUE, 0);

    GtkWidget *welcome_label = gtk_label_new("Welcome to Eth3r");
    gtk_widget_set_name(welcome_label, "welcome_label");
    gtk_box_pack_start(GTK_BOX(main_content), welcome_label, FALSE, FALSE, 0);

    search_entry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(search_entry), "Search with Google");
    gtk_widget_set_name(search_entry, "search_entry");
    gtk_box_pack_start(GTK_BOX(main_content), search_entry, FALSE, FALSE, 0);

    command_bar = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(command_bar), ": Enter command or search");
    gtk_widget_set_name(command_bar, "command_bar");
    gtk_widget_set_no_show_all(command_bar, TRUE);
    gtk_box_pack_end(GTK_BOX(main_content), command_bar, FALSE, FALSE, 0);

    // Static function as wrapper for signal handlers
    g_signal_connect(window, "motion-notify-event", G_CALLBACK(on_mouse_motion_wrapper), this);
    g_signal_connect(window, "key-press-event", G_CALLBACK(on_key_press_wrapper), this);

    gtk_window_set_resizable(GTK_WINDOW(window), TRUE);

    gtk_widget_show_all(window);
}

gboolean MainWindow::on_mouse_motion(GtkWidget *widget, GdkEventMotion *event, gpointer data) {
    MainWindow *self = static_cast<MainWindow *>(data);
    if (event->x < 10) {
        self->toggle_sidebar(true);
    } else if (event->x > 210) {
        self->toggle_sidebar(false);
    }
    return FALSE;
}

void MainWindow::toggle_sidebar(bool show) {
    if (show) {
        gtk_widget_show(sidebar);
    } else {
        gtk_widget_hide(sidebar);
    }
}

gboolean MainWindow::on_key_press(GtkWidget *widget, GdkEventKey *event, gpointer data) {
    MainWindow *self = static_cast<MainWindow *>(data);
    if ((event->state & GDK_CONTROL_MASK) && event->keyval == GDK_KEY_s) {
        gtk_widget_show(self->command_bar);
        gtk_widget_grab_focus(self->command_bar);
        return TRUE;
    }
    if (event->keyval == GDK_KEY_Return && gtk_widget_get_visible(self->command_bar)) {
        const gchar *input = gtk_entry_get_text(GTK_ENTRY(self->command_bar));
        if (input[0] == ':') {
            self->execute_command(input + 1);
        } else {
            self->search_query(input);
        }
        gtk_widget_hide(self->command_bar);
        gtk_widget_grab_focus(self->search_entry);
        return TRUE;
    }
    return FALSE;
}
void MainWindow::load_styles(const char *css_path) {
    GtkCssProvider *provider = gtk_css_provider_new();
    GdkScreen *screen = gdk_screen_get_default();
    gtk_style_context_add_provider_for_screen(screen, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

    GError *error = nullptr;
    gtk_css_provider_load_from_path(provider, css_path, &error);
    if (error) {
        g_printerr("Failed to load CSS file: %s\n", error->message);
        g_error_free(error);
    }

    g_object_unref(provider);
}


void MainWindow::execute_command(const gchar *command) {
    g_print("Executing command: %s\n", command);
}

void MainWindow::search_query(const gchar *query) {
    g_print("Searching for: %s\n", query);
}
static gboolean on_mouse_motion_wrapper(GtkWidget *widget, GdkEventMotion *event, gpointer data) {
    MainWindow *self = static_cast<MainWindow*>(data);
    return self->on_mouse_motion(widget, event, data);
}

static gboolean on_key_press_wrapper(GtkWidget *widget, GdkEventKey *event, gpointer data) {
    MainWindow *self = static_cast<MainWindow*>(data);
    return self->on_key_press(widget, event, data);
}

