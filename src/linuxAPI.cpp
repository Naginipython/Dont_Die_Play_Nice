#include "linuxAPI.h"

bool create_window(int width, int height, std::string title) {
    display = XOpenDisplay(NULL);
    if (display == NULL) {
        std::cout << "Unable to open window" << std::endl;
        return false;
    }
    screen = DefaultScreen(display);

    window = XCreateSimpleWindow(display, RootWindow(display, screen), POSX, POSY, width, height, 1,
                            BlackPixel(display, screen), WhitePixel(display, screen));

    XMapWindow(display, window);

    return true;
}

void update_window() { 
    XEvent event;
    while (!XNextEvent(display, &event)) {

    }
    XPending(display);
}

void kill_window() {
    XUnmapWindow(display, window);
    XDestroyWindow(display, window);
    XCloseDisplay(display);
}