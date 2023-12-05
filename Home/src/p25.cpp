#include <graphics.h>
#include <stdio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    int xc, yc, rx, ry;

    printf("Enter the center coordinates of the ellipse (xc yc): ");
    scanf("%d %d", &xc, &yc);

    printf("Enter the major and minor axes of the ellipse (rx ry): ");
    scanf("%d %d", &rx, &ry);

    ellipse(xc, yc, 0, 360, rx, ry);

    getch();
    closegraph();
    return 0;
}
