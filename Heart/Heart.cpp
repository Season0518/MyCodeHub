#include <iostream>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.1415926535
#define MAX_WIDTH GetSystemMetrics(SM_CXSCREEN)
#define MAX_HEIGHT GetSystemMetrics(SM_CXSCREEN)


void Draw(HDC hdc, int x, int y)
{
    double size = rand() % 5 + 1;
    int max = pow(size, 2) * 200;
    COLORREF color = RGB(rand() % 255, rand() % 255, rand() % 255);

    for (int i = 0; i < max; i++) {
        double t = ((double)i / max) * 2 * PI;
        SetPixel(hdc, x + 16 * size* (pow(sin(t), 3)), y - size*(13 * cos(t) - 5 * cos(2 * t) - 2 * cos(3 * t) - cos(4 * t)),color);
    }
    return;
}

int main()
{
    srand((unsigned)time(0));
    HWND hwnd;
    HDC hdc;
    hwnd = GetDesktopWindow();
    hdc = GetWindowDC(hwnd);
    for (int i = 0; i < 50; i++) {
        Draw(hdc, rand()%MAX_WIDTH,rand()%MAX_HEIGHT);
    }
    while (1);
    return 0;
}