#include <graphics.h>
#include <stdlib.h>
#include <time.h>

// Function to draw a balloon at coordinates (x, y) with a random color
void drawBalloon(int x, int y)
{
    int radius = 20;
    int color = rand() % 15 + 1; // Random color

    setcolor(color);
    setfillstyle(SOLID_FILL, color);
    circle(x, y, radius);
    floodfill(x, y, color);
}

int main()
{
    int gd = DETECT, gm;

    char data[] = "C:\\MinGW\\lib\\libbgi.a"; // static file

    initgraph(&gd, &gm, data);

    srand(time(NULL));

    int x, y;

    // Draw flying balloons
    for (int i = 0; i < 100; ++i)
    {
        x = rand() % getmaxx();
        y = rand() % getmaxy();

        drawBalloon(x, y);

        delay(100);
        cleardevice();
    }

    getch();
    closegraph();
    return 0;
}
