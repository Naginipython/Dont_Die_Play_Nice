#include <iostream>
#include <thread>
#include "generator.h"
#include "console.h"
#include "ddpn_lib.h"

#define APIENTRY
#include "glcorearb.h"

#include "platformAPI.h"
#include "gl_renderer.h"

using namespace std;

bool mainloopRunning = true;
bool debug = true;

int main() {
    create_window(400, 250, "DDPN");

    // mainloop
    while (mainloopRunning) {
        // SM_TRACE("test");
        // SM_WARN("test");
        // SM_ERROR("test");
        // SM_ASSERT(false, "Assert failed");
        update_window();
    }

    // kill_window();

    return 0;
}