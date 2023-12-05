#include <graphics.h>
#include <math.h>

// Function to rotate a point (x, y) around the center (cx, cy)
void rotatePoint(int *x, int *y, int cx, int cy, float angle)
{
    int tempX, tempY;
    angle = (angle * M_PI) / 180.0; // Convert angle to radians

    // Translate the point to the origin
    tempX = *x - cx;
    tempY = *y - cy;

    // Rotate the point
    *x = cx + (int)(tempX * cos(angle) - tempY * sin(angle));
    *y = cy + (int)(tempX * sin(angle) + tempY * cos(angle));
}

int main()
{
    int gd = DETECT, gm;
    char data[] = "C:\\MinGW\\lib\\libbgi.a"; // static file

    initgraph(&gd, &gm, data);

    int outerCircleX = 300, outerCircleY = 300, outerCircleRadius = 100;
    int rotatingCircleRadius = 20;
    float angle = 0;

    while (!kbhit())
    {
        cleardevice();

        // Draw the outer circle
        setcolor(BLUE);
        circle(outerCircleX, outerCircleY, outerCircleRadius);

        // Calculate the position of the rotating circle
        int rotatingCircleX = outerCircleX + outerCircleRadius + rotatingCircleRadius + 10;
        int rotatingCircleY = outerCircleY;

        // Rotate the position of the rotating circle
        rotatePoint(&rotatingCircleX, &rotatingCircleY, outerCircleX, outerCircleY, angle);

        // Draw the rotating circle
        setcolor(RED);
        circle(rotatingCircleX, rotatingCircleY, rotatingCircleRadius);

        angle += 1; // Increment the rotation angle

        delay(50);
    }

    getch();
    closegraph();
    return 0;
}
