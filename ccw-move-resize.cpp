#include <windows.h>
#include <iostream>

void MoveResizeWindow(const char* windowTitle, int x, int y, int width, int height) {
    HWND hwnd = FindWindow(NULL, windowTitle);
    if (hwnd == NULL) {
        std::cerr << "Could not find window: " << windowTitle << std::endl;
        return;
    }

    MoveWindow(hwnd, x, y, width, height, TRUE);
    std::cout << "Window moved and resized: " << windowTitle << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 6) {
        std::cerr << "Usage: " << argv[0] << " [window title] [x] [y] [width] [height]" << std::endl;
        return 1;
    }

    MoveResizeWindow(argv[1], atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), atoi(argv[5]));
    return 0;
}
