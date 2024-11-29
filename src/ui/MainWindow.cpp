#include <gtk/gtk.h>
#include <webkit2/webkit2.h>

static gboolean on_key_press(GtkWidget *widget, GdkEventKey *event, gpointer user_data) {
    WebKitWebView *webview = WEBKIT_WEB_VIEW(user_data);  // Get the WebKitWebView

    switch (event->keyval) {
        case GDK_KEY_h: // Go back in history
            webkit_web_view_go_back(webview);
            break;
        case GDK_KEY_l: // Go forward in history
            webkit_web_view_go_forward(webview);
            break;
        case GDK_KEY_j: // Scroll down
            webkit_web_view_evaluate_javascript(webview, "window.scrollBy(0, 100);", NULL, NULL, NULL);
            break;
        case GDK_KEY_k: // Scroll up
            webkit_web_view_evaluate_javascript(webview, "window.scrollBy(0, -100);", NULL, NULL, NULL);
            break;
        case GDK_KEY_G: // Jump to bottom of page
            webkit_web_view_evaluate_javascript(webview, "window.scrollTo(0, document.body.scrollHeight);", NULL, NULL, NULL);
            break;
        case GDK_KEY_g: // Jump to top of page
            webkit_web_view_evaluate_javascript(webview, "window.scrollTo(0, 0);", NULL, NULL, NULL);
            break;
        // Add more cases for other Vim-like navigation commands...
    }

    return FALSE; // Return FALSE to allow further processing of the event
}

void on_activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "EtherBrowser");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);

    // WebView setup
    WebKitWebView *webview = WEBKIT_WEB_VIEW(webkit_web_view_new());
    gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(webview));

    // Load a URL to test
    webkit_web_view_load_uri(webview, "https://www.example.com");

    // Connect the key press event
    g_signal_connect(window, "key-press-event", G_CALLBACK(on_key_press), webview);

    gtk_widget_show_all(window);
}

int main(int argc, char *argv[]) {
    GtkApplication *app = gtk_application_new("org.webkitgtk.example", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}

