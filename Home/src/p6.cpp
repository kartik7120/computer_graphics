#include <graphics.h>

// Function to scale a point (x, y) with respect to a reference point (refX, refY)
void scalePoint(int *x, int *y, int refX, int refY, float scaleX, float scaleY)
{
    *x = refX + (int)((*x - refX) * scaleX);
    *y = refY + (int)((*y - refY) * scaleY);
}

int main()
{
    int gd = DETECT, gm;

    char data[] = "C:\\MinGW\\lib\\libbgi.a"; // static file

    initgraph(&gd, &gm, data);

    // Coordinates of the rectangle
    int x1 = 100, y1 = 100, x2 = 200, y2 = 200;
    int refX = 150, refY = 150; // Reference point for scaling

    float scaleX = 1.5; // Scale factor along the x-axis
    float scaleY = 0.8; // Scale factor along the y-axis

    // Draw the original rectangle
    rectangle(x1, y1, x2, y2);

    // Scale each point of the rectangle
    scalePoint(&x1, &y1, refX, refY, scaleX, scaleY);
    scalePoint(&x2, &y2, refX, refY, scaleX, scaleY);

    // Draw the scaled rectangle
    setcolor(RED);
    rectangle(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}
