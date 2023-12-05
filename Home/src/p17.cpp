#include <graphics.h>
#include <conio.h>

void drawBicycle(int x, int y)
{
    // Draw bicycle frame
    setcolor(BROWN);
    rectangle(x, y - 20, x + 100, y + 20);
    rectangle(x + 80, y - 20, x + 100, y + 20);
    rectangle(x + 20, y - 20, x + 80, y - 10);
    rectangle(x + 20, y + 10, x + 80, y + 20);

    // Draw wheels
    setcolor(DARKGRAY);
    circle(x + 20, y - 20, 15);
    circle(x + 80, y - 20, 15);
}

int main()
{
    int gd = DETECT, gm;
    char data[] = "C:\\MinGW\\lib\\libbgi.a"; // static file

    initgraph(&gd, &gm, data);

    int x = 0;
    int y = getmaxy() / 2;

    while (!kbhit())
    {
        cleardevice();

        drawBicycle(x, y);

        delay(50); // Adjust the delay for the animation speed

        x += 5; // Move the bicycle to the right

        // Reset the position when the bicycle goes off the screen
        if (x > getmaxx())
        {
            x = 0;
        }
    }

    getch();
    closegraph();
    return 0;
}
