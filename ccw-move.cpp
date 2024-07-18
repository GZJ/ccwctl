
#include <windows.h>
#include <iostream>

void MoveWindowPosition(const char* windowTitle, int x, int y) {
    HWND hwnd = FindWindow(NULL, windowTitle);
    if (hwnd == NULL) {
        std::cerr << "Could not find window: " << windowTitle << std::endl;
        return;
    }

    RECT rect;
    GetWindowRect(hwnd, &rect);
    MoveWindow(hwnd, x, y, rect.right - rect.left, rect.bottom - rect.top, TRUE);
    std::cout << "Window moved: " << windowTitle << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " [window title] [x] [y]" << std::endl;
        return 1;
    }

    MoveWindowPosition(argv[1], atoi(argv[2]), atoi(argv[3]));
    return 0;
}
