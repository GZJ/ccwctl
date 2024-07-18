#include <windows.h>
#include <iostream>

void ResizeWindow(const char* windowTitle, int width, int height) {
    HWND hwnd = FindWindow(NULL, windowTitle);
    if (hwnd == NULL) {
        std::cerr << "Could not find window: " << windowTitle << std::endl;
        return;
    }

    RECT rect;
    GetWindowRect(hwnd, &rect);
    MoveWindow(hwnd, rect.left, rect.top, width, height, TRUE);
    std::cout << "Window resized: " << windowTitle << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " [window title] [width] [height]" << std::endl;
        return 1;
    }

    ResizeWindow(argv[1], atoi(argv[2]), atoi(argv[3]));
    return 0;
}
