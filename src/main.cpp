#if __WIN32
    #include "windowsAPI.h"
    int os = 0;
#elif __linux__
    #include "linuxAPI.h"
    int os = 1;
#else
    int os = 2;
#endif

#include <iostream>
#include <thread>
#include "generator.h"
#include "console.h"
#include "ddpn_lib.h"

using namespace std;

bool debug = true;

bool gameloopRunning = true;
bool promptedGLRunning = false;

int main() {
    create_window(400, 250, "DDPN");

    // mainloop
    while (gameloopRunning) {
        SM_TRACE("test");
        SM_WARN("test");
        SM_ERROR("test");
        SM_ASSERT(false, "Assert failed");
        break;
        update_window();
        // if (debug) {
        //     if (!promptedGLRunning) {
        //         cout << "Running: Gameloop" << endl;
        //         promptedGLRunning = true;
        //     }
        // }
    }

    kill_window();

    return 0;
}