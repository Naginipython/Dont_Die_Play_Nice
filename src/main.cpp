#include <iostream>
#include <thread>
#include "platformAPI.h"
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
        // SM_TRACE("test");
        // SM_WARN("test");
        // SM_ERROR("test");
        // SM_ASSERT(false, "Assert failed");
        update_window();
        // if (debug) {
        //     if (!promptedGLRunning) {
        //         cout << "Running: Gameloop" << endl;
        //         promptedGLRunning = true;
        //     }
        // }
    }

    // kill_window();

    return 0;
}