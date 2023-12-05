#include <graphics.h>
#include <conio.h>

void drawCircle(int xc, int yc, int radius)
{
    circle(xc, yc, radius);
}

int main()
{
    int gd = DETECT, gm;
    char data[] = "C:\\MinGW\\lib\\libbgi.a"; // static file

    initgraph(&gd, &gm, data);

    int xc = getmaxx() / 2;
    int yc = getmaxy() / 2;
    int radius = 50;

    char ch;
    int key;

    while (1)
    {
        cleardevice(); // Clear the screen

        drawCircle(xc, yc, radius);

        ch = getch();
        key = ch;

        // Check arrow key input
        if (key == 0 || key == 224)
        {
            key = getch();
            switch (key)
            {
            case 72: // Up arrow key
                radius += 5;
                break;
            case 80: // Down arrow key
                radius -= 5;
                if (radius < 5)
                {
                    radius = 5;
                }
                break;
            }
        }

        if (key == 27)
        { // 27 is ASCII code for Esc key
            break;
        }
    }

    closegraph();
    return 0;
}
