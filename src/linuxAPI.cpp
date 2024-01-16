#include <X11/Xutil.h>
#include <iostream>
#include "platform.h"

bool create_window(int width, int height, std::string title) {
    display = XOpenDisplay(NULL);
    if (display == NULL) {
        std::cout << "Unable to open window" << std::endl;
        return false;
    }
    screen = DefaultScreen(display);

    window = XCreateSimpleWindow(display, RootWindow(display, screen), POSX, POSY, width, height, 1,
        BlackPixel(display, screen), WhitePixel(display, screen));

    XStoreName(display, window, title.c_str());
    XSelectInput(display, window, KeyPressMask);

    XMapWindow(display, window);

    return true;
}

void update_window() {
    XEvent event;
    if (XPending(display)) {
        XNextEvent(display, &event);
        printf("EVENT: %d\n", event.type);

        if (event.type == KeyPress) {
            printf("KeyPress Event: %d\n", event.xkey.keycode);
            KeySym keysym = XLookupKeysym(&event.xkey, 0);
            switch (keysym) {
                case XK_Up: printf("Pressed Up\n"); break;
                case XK_Right: printf("Pressed Right\n"); break;
                case XK_Down: printf("Pressed Down\n"); break;
                case XK_Left: printf("Pressed Left\n"); break;
                case XK_space: printf("Pressed space\n"); break;
                case XK_Escape: printf("Pressed Esc\n"); break;
            }
        }
    }
    // while (!XNextEvent(display, &event)) {
    //     std::cout << "inside linux update_window loop" << std::endl;
    // }
}

void kill_window() {
    XUnmapWindow(display, window);
    XDestroyWindow(display, window);
    XCloseDisplay(display);
}