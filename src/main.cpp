#include <iostream>
#include <thread>
#include "..\include\generator.h"
#include "..\include\console.h"
#include "..\include\windowsAPI.h"

bool debug = true;

bool gameloopRunning = true;
bool promptedGLRunning = false;
bool importTested = false;
bool consoleStarted = false;

int main() {
    win32_create_window(400, 250, "DDPN");
    while (gameloopRunning) {
        if (debug) {
            if (!promptedGLRunning) {
                std::cout << "Running: Gameloop" << std::endl;
                promptedGLRunning = true;
            }
            if (!importTested) {
                int result = generatorImportTest();
                std::cout << "Generator correctly imported: " << generatorImportTest() << std::endl;
                importTested = true;
            }
            if (!consoleStarted) {
                std::thread thread_obj(startConsole);
                thread_obj.join();
                consoleStarted = true;
            }
        }
    }

    return 0;
}