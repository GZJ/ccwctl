#include <windows.h>
#include <iostream>

void MaximizeWindow(const char* windowTitle) {
    HWND hwnd = FindWindow(NULL, windowTitle);
    if (hwnd == NULL) {
        std::cerr << "Could not find window: " << windowTitle << std::endl;
        return;
    }

    ShowWindow(hwnd, SW_MAXIMIZE);
    std::cout << "Window maximized: " << windowTitle << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " [window title]" << std::endl;
        return 1;
    }

    MaximizeWindow(argv[1]);
    return 0;
}
