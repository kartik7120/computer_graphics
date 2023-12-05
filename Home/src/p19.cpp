#include <graphics.h>
#include <conio.h>

void drawCar(int x, int y)
{
    // Draw car body
    setcolor(BLUE);
    rectangle(x, y, x + 100, y + 50);
    rectangle(x + 10, y + 10, x + 90, y + 40);

    // Draw car windows
    setfillstyle(SOLID_FILL, CYAN);
    floodfill(x + 30, y + 15, BLUE);
    floodfill(x + 70, y + 15, BLUE);
}

int main()
{
    int gd = DETECT, gm;
    char data[] = "C:\\MinGW\\lib\\libbgi.a"; // static file

    initgraph(&gd, &gm, data);

    int maxX = getmaxx();

    int x = 0;
    int y = getmaxy() / 2;

    while (!kbhit())
    {
        cleardevice();

        drawCar(x, y);

        delay(50); // Adjust the delay for the animation speed

        x += 5; // Move the car to the right

        // Reset the position when the car goes off the screen
        if (x > maxX)
        {
            x = -100;
        }
    }

    getch();
    closegraph();
    return 0;
}
