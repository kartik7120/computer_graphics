#include <graphics.h>

// Function to reflect a point (x, y) with respect to a mirror line y = mx + c
void reflectPoint(int *x, int *y, float m, float c)
{
    float x_temp = *x;
    float y_temp = *y;

    // Use the formula for reflection across a line: x' = x - 2m(y - c)/(1 + m^2), y' = 2mx + 2c - y
    *x = (int)(x_temp - 2 * m * (y_temp - c) / (1 + m * m));
    *y = (int)(2 * m * x_temp + 2 * c - y_temp);
}

int main()
{
    int gd = DETECT, gm;

    char data[] = "C:\\MinGW\\lib\\libbgi.a"; // static file

    initgraph(&gd, &gm, data);
    // Coordinates of the triangle
    int x1 = 100, y1 = 100, x2 = 200, y2 = 100, x3 = 150, y3 = 200;

    // Draw the original triangle
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    // Equation of the mirror line: y = mx + c
    float m = -1;  // Slope of the mirror line
    float c = 150; // Y-intercept of the mirror line

    // Reflect each point of the triangle
    reflectPoint(&x1, &y1, m, c);
    reflectPoint(&x2, &y2, m, c);
    reflectPoint(&x3, &y3, m, c);

    // Draw the reflected triangle
    setcolor(RED);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    getch();
    closegraph();
    return 0;
}
