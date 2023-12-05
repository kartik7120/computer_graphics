#include <graphics.h>
#include <stdio.h>
#include<cmath>
using namespace std;

void drawRotatingCircle(int xc, int yc, int radius, int angle)
{
    int x = xc + radius * cos(angle * 3.14 / 180);
    int y = yc + radius * sin(angle * 3.14 / 180);

    circle(xc, yc, radius); // Outer circle
    circle(x, y, 10);       // Inner rotating circle
}

int main()
{
    int gd = DETECT, gm;
    char data[] = "C:\\MinGW\\lib\\libbgi.a"; // static file

    initgraph(&gd, &gm, data);

    int xc = getmaxx() / 2;
    int yc = getmaxy() / 2;
    int outerRadius = 100;
    int innerRadius = 10;
    int angle = 0;

    while (!kbhit())
    {
        cleardevice(); // Clear the screen

        drawRotatingCircle(xc, yc, outerRadius, angle);
        angle += 5; // Adjust the speed of rotation

        delay(50); // Introduce a delay to control the speed of rotation
    }

    getch();
    closegraph();
    return 0;
}
