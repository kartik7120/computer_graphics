#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int gd = DETECT, gm;
    char data[] = "C:\\MinGW\\lib\\libbgi.a"; // static file

    initgraph(&gd, &gm, data);

    int x = getmaxx() / 2; // Initial x-coordinate of the ball
    int y = getmaxy() / 2; // Initial y-coordinate of the ball
    int radius = 20;       // Radius of the ball
    int xSpeed = 5;        // Initial speed of the ball along the x-axis
    int ySpeed = 3;        // Initial speed of the ball along the y-axis

    while (!kbhit())
    {
        // Clear the previous frame
        cleardevice();

        // Draw the ball
        setcolor(YELLOW);
        setfillstyle(SOLID_FILL, YELLOW);
        circle(x, y, radius);
        floodfill(x, y, YELLOW);

        // Move the ball
        x += xSpeed;
        y += ySpeed;

        // Check for collisions with the screen boundaries
        if (x - radius < 0 || x + radius > getmaxx())
        {
            xSpeed = -xSpeed; // Reverse the x-direction
        }
        if (y - radius < 0 || y + radius > getmaxy())
        {
            ySpeed = -ySpeed; // Reverse the y-direction
        }

        delay(30); // Adjust the delay for the animation speed
    }

    getch();
    closegraph();
    return 0;
}
