
#ifndef _FFENESTRI_WINDOWS_H
#define _FFENESTRI_WINDOWS_H

#define WIN32_LEAN_AND_MEAN
#define UNICODE 1

#include "ffenestri.h"
#include <windows.h>
#include <wingdi.h>
#include <functional>
#include <codecvt>
#include "windows/WebView2.h"

#include "assets.h"

// TODO:
//#include "userdialogicons.h"


struct Application{
    // Window specific
    HWND window;
    ICoreWebView2 *webview;
    ICoreWebView2Controller* webviewController;

    // Application
    const char *title;
    int width;
    int height;
    int resizable;
    int devtools;
    int fullscreen;
    int startHidden;
    int logLevel;
    int hideWindowOnClose;
    int minSizeSet;
    LONG minWidth;
    LONG minHeight;
    int maxSizeSet;
    LONG maxWidth;
    LONG maxHeight;
    int frame;
    char *startupURL;
    bool webviewIsTranparent;
    bool windowBackgroundIsTranslucent;
    COREWEBVIEW2_COLOR backgroundColour;
    bool disableWindowIcon;

    // Used by fullscreen/unfullscreen
    bool isFullscreen;
    WINDOWPLACEMENT previousPlacement;
    DWORD previousWindowStyle;

    // placeholders
    char* bindings;
    char* initialCode;

    // DPI
    UINT dpix;
    UINT dpiy;
};

#define ON_MAIN_THREAD(code) dispatch( [=]{ code; } )

typedef std::function<void()> dispatchFunction;
typedef std::function<void(const std::string)> messageCallback;
typedef std::function<void(ICoreWebView2Controller *)> comHandlerCallback;

void center(struct Application*);
void setTitle(struct Application* app, const char *title);
void fullscreen(struct Application* app);
void unfullscreen(struct Application* app);
char* LPWSTRToCstr(LPWSTR input);

// called when the DOM is ready
void loadAssets(struct Application* app);

// called when the application assets have been loaded into the DOM
void completed(struct Application* app);

// Callback
extern "C" {
    void DisableWindowIcon(struct Application* app);
    void messageFromWindowCallback(const char *);
    void* GetWindowHandle(struct Application*);
    void createApplicationMenu(HWND hwnd);
    void menuClicked(UINT id);
}

#endif