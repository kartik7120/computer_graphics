#include <graphics.h>

int main()
{
    int gd = DETECT, gm;
    char data[] = "C:\\MinGW\\lib\\libbgi.a"; // static file

    initgraph(&gd, &gm, data);

    int centerX = getmaxx() / 2;
    int centerY = getmaxy() / 2;

    int initialRadius = 20;
    int maxRadius = 100;
    int radiusChange = 2;

    int radius = initialRadius;

    while (!kbhit() && radius <= maxRadius)
    {
        cleardevice();

        // Draw the circle with the changing radius
        setcolor(BLUE);
        circle(centerX, centerY, radius);

        delay(50); // Adjust the delay for the animation speed

        radius += radiusChange;
    }

    getch();
    closegraph();
    return 0;
}
