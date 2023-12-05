#include <graphics.h>
#include <stdio.h>
#include <math.h>

void scaleLine(int x1, int y1, int x2, int y2, float scaleX, float scaleY)
{
    x1 = round(x1 * scaleX);
    y1 = round(y1 * scaleY);
    x2 = round(x2 * scaleX);
    y2 = round(y2 * scaleY);

    line(x1, y1, x2, y2);
}

int main()
{
    int gd = DETECT, gm;
    char data[] = "C:\\MinGW\\lib\\libbgi.a"; // static file

    initgraph(&gd, &gm, data);

    int x1, y1, x2, y2;
    float scaleX, scaleY;

    printf("Enter the coordinates of the line (x1 y1 x2 y2): ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    printf("Enter the scaling factors (scaleX scaleY): ");
    scanf("%f %f", &scaleX, &scaleY);

    setcolor(RED);
    line(x1, y1, x2, y2); // Original line in red

    setcolor(GREEN);
    scaleLine(x1, y1, x2, y2, scaleX, scaleY); // Scaled line in green

    getch();
    closegraph();
    return 0;
}
