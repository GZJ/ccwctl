#include <iostream>
#include <windows.h>

void SetWindowStyle(HWND hWnd)
{
    if (hWnd != NULL)
    {
        LONG_PTR exStyle = GetWindowLongPtr(hWnd, GWL_EXSTYLE);
        SetWindowLongPtr(hWnd, GWL_EXSTYLE, (exStyle | WS_EX_APPWINDOW) & ~WS_EX_TOOLWINDOW);
    }
    else
    {
        std::cerr << "Window not found." << std::endl;
    }
}

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cerr << "Please provide a window title as an argument." << std::endl;
        return 1;
    }

    HWND hWnd = FindWindowA(NULL, argv[1]);
    SetWindowStyle(hWnd);

    return 0;
}
