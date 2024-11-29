#ifndef BROWSER_ENGINE_H
#define BROWSER_ENGINE_H

#include <gtk/gtk.h>
#include <webkit2/webkit2.h>

class BrowserEngine {
public:
    BrowserEngine();
    ~BrowserEngine();

    void loadPage(const gchar* url);
    void goBack();
    void goForward();
    void scrollDown();
    void scrollUp();

private:
    WebKitWebView* webView;
};

#endif // BROWSER_ENGINE_H
