#include <graphics.h>
#include <stdio.h>

void drawCube(int x1, int y1, int x2, int y2, int z1, int z2)
{
    // Draw the front face of the cube
    rectangle(x1, y1, x2, y2);

    // Draw lines connecting front and back faces
    line(x1, y1, x1 + z1, y1 - z1);
    line(x2, y2, x2 + z1, y2 - z1);
    line(x1, y2, x1 + z1, y2 - z1);
    line(x2, y1, x2 + z1, y1 - z1);

    // Draw the back face of the cube
    rectangle(x1 + z1, y1 - z1, x2 + z2, y2 - z2);
}

void translateCube(int &x1, int &y1, int &x2, int &y2, int &z1, int &z2, int tx, int ty, int tz)
{
    x1 += tx;
    y1 += ty;
    x2 += tx;
    y2 += ty;
    z1 += tz;
    z2 += tz;
}

int main()
{
    int gd = DETECT, gm;
    char data[] = "C:\\MinGW\\lib\\libbgi.a"; // static file

    initgraph(&gd, &gm, data);

    int x1 = 100, y1 = 100, x2 = 200, y2 = 200, z1 = 0, z2 = 50;

    drawCube(x1, y1, x2, y2, z1, z2);

    int tx, ty, tz;

    printf("Enter the translation factors (tx ty tz): ");
    scanf("%d %d %d", &tx, &ty, &tz);

    cleardevice(); // Clear the screen

    translateCube(x1, y1, x2, y2, z1, z2, tx, ty, tz);
    drawCube(x1, y1, x2, y2, z1, z2);

    getch();
    closegraph();
    return 0;
}
