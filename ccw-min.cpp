#include <windows.h>
#include <iostream>

void MinimizeWindow(const char* windowTitle) {
    HWND hwnd = FindWindow(NULL, windowTitle);
    if (hwnd == NULL) {
        std::cerr << "Could not find window: " << windowTitle << std::endl;
        return;
    }

    ShowWindow(hwnd, SW_MINIMIZE);
    std::cout << "Window minimized: " << windowTitle << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " [window title]" << std::endl;
        return 1;
    }

    MinimizeWindow(argv[1]);
    return 0;
}
