#include <graphics.h>
#include <math.h>

void drawTable()
{
    // Draw the table
    setcolor(BROWN);
    rectangle(50, 300, getmaxx() - 50, getmaxy() - 50);
}

void drawRotatingCoin(int centerX, int centerY, int radius, int angle)
{
    // Calculate the new position of the coin based on the rotation angle
    int newX = centerX + (int)(radius * cos(angle * M_PI / 180));
    int newY = centerY + (int)(radius * sin(angle * M_PI / 180));

    // Draw the coin
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    circle(newX, newY, 10);
    floodfill(newX, newY, YELLOW);
}

int main()
{
    int gd = DETECT, gm;
    char data[] = "C:\\MinGW\\lib\\libbgi.a"; // static file

    initgraph(&gd, &gm, data);

    int centerX = getmaxx() / 2;
    int centerY = getmaxy() - 100;
    int radius = 50;
    int angle = 0;

    while (!kbhit())
    {
        cleardevice();

        drawTable(); // Draw the table

        drawRotatingCoin(centerX, centerY, radius, angle);

        delay(50); // Adjust the delay for the animation speed

        angle += 5; // Increment the rotation angle
        if (angle > 360)
        {
            angle = 0;
        }
    }

    getch();
    closegraph();
    return 0;
}
