#include <graphics.h>
#include <conio.h>
#include <stdlib.h>

void drawStar(int x, int y)
{
    setcolor(YELLOW);
    putpixel(x, y, YELLOW);
    putpixel(x + 1, y, YELLOW);
    putpixel(x, y + 1, YELLOW);
    putpixel(x - 1, y, YELLOW);
    putpixel(x, y - 1, YELLOW);
}

int main()
{
    int gd = DETECT, gm;
    char data[] = "C:\\MinGW\\lib\\libbgi.a"; // static file

    initgraph(&gd, &gm, data);

    int maxX = getmaxx();
    int maxY = getmaxy();

    // Generate initial random positions for stars
    int numStars = 100;
    int starX[numStars];
    int starY[numStars];

    for (int i = 0; i < numStars; i++)
    {
        starX[i] = rand() % maxX;
        starY[i] = rand() % maxY;
    }

    while (!kbhit())
    {
        cleardevice();

        // Draw stars
        for (int i = 0; i < numStars; i++)
        {
            drawStar(starX[i], starY[i]);

            // Move stars and reset if they go off the screen
            starX[i] += rand() % 5 - 2; // Random movement along x-axis
            starY[i] += rand() % 5 - 2; // Random movement along y-axis

            if (starX[i] < 0 || starX[i] >= maxX || starY[i] < 0 || starY[i] >= maxY)
            {
                starX[i] = rand() % maxX;
                starY[i] = rand() % maxY;
            }
        }

        delay(50); // Adjust the delay for the screensaver speed
    }

    getch();
    closegraph();
    return 0;
}
