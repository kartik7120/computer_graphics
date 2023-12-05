#include <graphics.h>
#include <stdio.h>

void drawCircle(int xc, int yc, int radius)
{
    int x = 0;
    int y = radius;
    int p = 1 - radius; // Initial decision parameter

    // Plot the initial point
    putpixel(xc + x, yc - y, RED);

    // Draw the circle using the Midpoint Circle Algorithm
    while (x < y)
    {
        x++;

        if (p < 0)
        {
            p += 2 * x + 1;
        }
        else
        {
            y--;
            p += 2 * (x - y) + 1;
        }

        // All the perimeter points have already been printed
        if (x > y)
        {
            break;
        }

        // If the generated point is on the line x = y, then the perimeter points
        // have already been printed, and a new point will be generated on the next iteration
        if (x != y)
        {
            putpixel(xc + x, yc - y, RED);
            putpixel(xc - x, yc - y, RED);
            putpixel(xc + x, yc + y, RED);
            putpixel(xc - x, yc + y, RED);
        }

        putpixel(xc + y, yc - x, RED);
        putpixel(xc - y, yc - x, RED);
        putpixel(xc + y, yc + x, RED);
        putpixel(xc - y, yc + x, RED);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    int xc, yc, radius;

    printf("Enter the center coordinates of the circle (xc yc): ");
    scanf("%d %d", &xc, &yc);

    printf("Enter the radius of the circle: ");
    scanf("%d", &radius);

    drawCircle(xc, yc, radius);

    getch();
    closegraph();
    return 0;
}
