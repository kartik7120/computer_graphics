#include <math.h>
#include <stdio.h>
#include <graphics.h>
using namespace std;

// Define a 3D point structure
struct Point3D
{
    float x, y, z;
};

// Function to perform a 3D translation
void translate3D(struct Point3D *point, float Tx, float Ty, float Tz)
{
    point->x += Tx;
    point->y += Ty;
    point->z += Tz;
}

// int main()
// {
//     // Create a 3D point
//     struct Point3D point = {1.0, 2.0, 3.0};

//     // Translation amounts
//     float Tx = 2.0; // Translation along the x-axis
//     float Ty = 3.0; // Translation along the y-axis
//     float Tz = 4.0; // Translation along the z-axis

//     // Perform the translation
//     translate3D(&point, Tx, Ty, Tz);

//     // Print the updated coordinates
//     printf("Translated Point: (%.2f, %.2f, %.2f)\n", point.x, point.y, point.z);
//     return 0;
// }

#define PI 3.14159265358979323846

// Function to rotate a point (x, y) around the center (cx, cy)
void rotatePoint(int *x, int *y, int cx, int cy, float angle)
{
    int tempX, tempY;
    angle = (angle * PI) / 180.0;

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

    // Coordinates of the square
    int x1 = 100, y1 = 100, x2 = 200, y2 = 200, x3 = 200, y3 = 100, x4 = 100, y4 = 200;

    int cx = (x1 + x3) / 2; // x-coordinate of the center
    int cy = (y1 + y3) / 2; // y-coordinate of the center

    int angle = 45; // Rotation angle in degrees

    // Draw the original square
    rectangle(x1, y1, x3, y3);

    // Rotate each point of the square
    rotatePoint(&x1, &y1, cx, cy, angle);
    rotatePoint(&x2, &y2, cx, cy, angle);
    rotatePoint(&x3, &y3, cx, cy, angle);
    rotatePoint(&x4, &y4, cx, cy, angle);

    // Draw the rotated square
    setcolor(RED);
    rectangle(x1, y1, x3, y3);

    getch();
    closegraph();
    return 0;
}
