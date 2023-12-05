#include <graphics.h>

// Function to shear a point (x, y) with respect to the shearing factors (shx, shy)
void shearPoint(int *x, int *y, float shx, float shy)
{
    int x_temp = *x;
    int y_temp = *y;

    // Use the shearing formulas: x' = x + shx * y, y' = y + shy * x
    *x = x_temp + (int)(shx * y_temp);
    *y = y_temp + (int)(shy * x_temp);
}

int main()
{
    int gd = DETECT, gm;

    char data[] = "C:\\MinGW\\lib\\libbgi.a"; // static file

    initgraph(&gd, &gm, data);
    // Coordinates of the rectangle
    int x1 = 100, y1 = 100, x2 = 200, y2 = 100, x3 = 200, y3 = 150, x4 = 100, y4 = 150;

    // Draw the original rectangle
    rectangle(x1, y1, x3, y3);

    // Shearing factors
    float shx = 0.5; // Shearing factor along the x-axis
    float shy = 0.0; // Shearing factor along the y-axis

    // Shear each point of the rectangle
    shearPoint(&x1, &y1, shx, shy);
    shearPoint(&x2, &y2, shx, shy);
    shearPoint(&x3, &y3, shx, shy);
    shearPoint(&x4, &y4, shx, shy);

    // Draw the sheared rectangle
    setcolor(RED);
    rectangle(x1, y1, x3, y3);

    getch();
    closegraph();
    return 0;
}
