#include <iostream>
#include <thread>
#include "generator.h"
#include "console.h"
#include "windowsAPI.h"

bool debug = true;

bool gameloopRunning = true;
bool promptedGLRunning = false;

int main() {
    win_create_window(400, 250, "DDPN");
    while (gameloopRunning) {
        win_update_window();
        if (debug) {
            if (!promptedGLRunning) {
                std::cout << "Running: Gamelop" << std::endl;
                promptedGLRunning = true;
            }
        }
    }

    return 0;
}