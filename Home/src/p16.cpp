#include <graphics.h>
#include <math.h>
#include <time.h>

void drawClock(int cx, int cy, int radius)
{
    // Draw the clock face
    setcolor(LIGHTGRAY);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    circle(cx, cy, radius);
    floodfill(cx, cy, LIGHTGRAY);

    // Draw the clock center
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    circle(cx, cy, 5);
    floodfill(cx, cy, BLACK);

    // Draw clock ticks
    for (int i = 0; i < 12; i++)
    {
        int tickLength = 10;
        int tickX = cx + (int)(radius * cos(i * M_PI / 6));
        int tickY = cy - (int)(radius * sin(i * M_PI / 6));
        int endX = cx + (int)((radius - tickLength) * cos(i * M_PI / 6));
        int endY = cy - (int)((radius - tickLength) * sin(i * M_PI / 6));

        line(tickX, tickY, endX, endY);
    }
}

void drawClockHands(int cx, int cy, int radius, int hours, int minutes, int seconds)
{
    // Draw hour hand
    int hourHandLength = radius / 2;
    int hourX = cx + (int)(hourHandLength * cos((90 - hours * 30 - minutes / 2.0) * M_PI / 180));
    int hourY = cy - (int)(hourHandLength * sin((90 - hours * 30 - minutes / 2.0) * M_PI / 180));
    setcolor(RED);
    line(cx, cy, hourX, hourY);

    // Draw minute hand
    int minuteHandLength = radius * 0.75;
    int minuteX = cx + (int)(minuteHandLength * cos((90 - minutes * 6) * M_PI / 180));
    int minuteY = cy - (int)(minuteHandLength * sin((90 - minutes * 6) * M_PI / 180));
    setcolor(GREEN);
    line(cx, cy, minuteX, minuteY);

    // Draw second hand
    int secondHandLength = radius * 0.9;
    int secondX = cx + (int)(secondHandLength * cos((90 - seconds * 6) * M_PI / 180));
    int secondY = cy - (int)(secondHandLength * sin((90 - seconds * 6) * M_PI / 180));
    setcolor(BLUE);
    line(cx, cy, secondX, secondY);
}

int main()
{
    int gd = DETECT, gm;
    char data[] = "C:\\MinGW\\lib\\libbgi.a"; // static file

    initgraph(&gd, &gm, data);

    int cx = getmaxx() / 2;
    int cy = getmaxy() / 2;
    int radius = 100;

    while (!kbhit())
    {
        cleardevice();

        // Get current time
        time_t t;
        time(&t);
        struct tm *currentTime = localtime(&t);
        int hours = currentTime->tm_hour;
        int minutes = currentTime->tm_min;
        int seconds = currentTime->tm_sec;

        drawClock(cx, cy, radius);
        drawClockHands(cx, cy, radius, hours, minutes, seconds);

        delay(1000); // Update every second
    }

    getch();
    closegraph();
    return 0;
}
