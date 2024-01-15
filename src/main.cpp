#if __WIN32
    #include "windowsAPI.h"
#elif __linux__
    int os = 1;
#else
    int os = 2;
#endif

#include <iostream>
#include <thread>
#include "generator.h"
#include "console.h"

using namespace std;

bool debug = true;

bool gameloopRunning = true;
bool promptedGLRunning = false;

int main() {
    create_window(400, 250, "DDPN");

    // mainloop
    while (gameloopRunning) {
        update_window();
        if (debug) {
            if (!promptedGLRunning) {
                cout << "Running: Gameloop" << endl;
                promptedGLRunning = true;
            }
        }
    }

    return 0;
}