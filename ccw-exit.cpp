#include <windows.h>
#include <iostream>

void ExitWindow(const char* windowTitle) {
    HWND hwnd = FindWindow(NULL, windowTitle);
    if (hwnd == NULL) {
        std::cerr << "Could not find window: " << windowTitle << std::endl;
        return;
    }

    PostMessage(hwnd, WM_CLOSE, 0, 0);
    std::cout << "Window closed: " << windowTitle << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " [window title]" << std::endl;
        return 1;
    }

    ExitWindow(argv[1]);
    return 0;
}
