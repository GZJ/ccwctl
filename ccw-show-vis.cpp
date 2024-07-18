#include <windows.h>
#include <iostream>

void ShowWindowVis(const char* windowTitle) {
    HWND hwnd = FindWindow(NULL, windowTitle);
    if (hwnd == NULL) {
        std::cerr << "Could not find window: " << windowTitle << std::endl;
        return;
    }

    ShowWindow(hwnd, SW_SHOW);
    std::cout << "Window shown: " << windowTitle << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " [window title]" << std::endl;
        return 1;
    }

    ShowWindowVis(argv[1]);
    return 0;
}
