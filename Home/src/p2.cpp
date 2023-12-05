#include <graphics.h>

void drawMidpointCircle(int xCenter, int yCenter, int radius)
{
    int x = radius;
    int y = 0;
    int p = 1 - radius; // Initial value of the midpoint parameter

    while (x >= y)
    {
        putpixel(xCenter + x, yCenter + y, WHITE);
        putpixel(xCenter - x, yCenter + y, WHITE);
        putpixel(xCenter + x, yCenter - y, WHITE);
        putpixel(xCenter - x, yCenter - y, WHITE);
        putpixel(xCenter + y, yCenter + x, WHITE);
        putpixel(xCenter - y, yCenter + x, WHITE);
        putpixel(xCenter + y, yCenter - x, WHITE);
        putpixel(xCenter - y, yCenter - x, WHITE);

        y++;

        if (p <= 0)
            p = p + 2 * y + 1;
        else
        {
            x--;
            p = p + 2 * y - 2 * x + 1;
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    int xCenter = 200, yCenter = 200, radius = 100;
    drawMidpointCircle(xCenter, yCenter, radius);

    getch();
    closegraph();

    return 0;
}
