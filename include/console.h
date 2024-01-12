#include <iostream>
#include <string>
using namespace std;

int startConsole() {
    string cmd = "";
    int mode = 0;

    while (true) {
        // mode-based prompt and commands
        if (mode == 0) {
            cout << "(dev)>> ";
        }
        else if (mode == 1) {
            cout << "(sys)>> ";
        }

        // Use getline to read entire line of input
        getline(cin, cmd);

        // close console
        if (cmd == "exit") {
            break;
        }
        
        // switch cmd mode
        if (cmd == "switch") {
            mode = (mode == 0) ? 1 : 0;
            continue; // Start the next iteration of the loop
        }

        // Execute command if in sys mode
        if (mode == 1) {
            if (cmd == "startWin") {
                // TODO implement window creation on command
            }
        }
        else if (mode == 1 && cmd != "") {
            int returnCode = system(cmd.c_str());
        }
    }

    return 0;
}