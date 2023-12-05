#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <math.h>

int main()
{
    int gd = DETECT, gm;
    int x = 300, y = 300, radius = 100;
    int angle = 0;

    char data[] = "C:\\MinGW\\lib\\libbgi.a"; // static file

    initgraph(&gd, &gm, data);

    while (!kbhit())
    {
        // Draw fan blades
        line(x, y, x + radius * cos(angle * 3.14 / 180), y + radius * sin(angle * 3.14 / 180));
        line(x, y, x + radius * cos((angle + 120) * 3.14 / 180), y + radius * sin((angle + 120) * 3.14 / 180));
        line(x, y, x + radius * cos((angle + 240) * 3.14 / 180), y + radius * sin((angle + 240) * 3.14 / 180));

        delay(50);
        cleardevice();

        angle += 5; // Adjust the speed of rotation
    }

    closegraph();
    return 0;
}
