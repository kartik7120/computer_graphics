#include <graphics.h>

int main()
{
    int gd = DETECT, gm;
    char data[] = "C:\\MinGW\\lib\\libbgi.a"; // static file

    initgraph(&gd, &gm, data);

    // Draw a circle
    circle(200, 200, 50);

    // Draw a rectangle
    rectangle(300, 100, 400, 200);

    // Draw a polygon (triangle)
    int polyPoints[] = {100, 100, 50, 200, 150, 200, 100, 100};
    drawpoly(3, polyPoints);

    getch();
    closegraph();

    return 0;
}
