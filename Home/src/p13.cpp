#include <graphics.h>
#include <math.h>
#include <string.h>

void drawPieChart(int cx, int cy, int radius, int values[], int n, char labels[][20])
{
    int start_angle = 0;

    for (int i = 0; i < n; i++)
    {
        int end_angle = start_angle + (360 * values[i]) / 100;

        // Draw pie slice
        setfillstyle(i + 1, i + 1); // Setting color for each slice
        pieslice(cx, cy, start_angle, end_angle, radius);

        // Draw legend
        rectangle(500, i * 30 + 50, 520, i * 30 + 70);
        floodfill(510, i * 30 + 60, i + 1);

        // Draw legend text
        setcolor(i + 1);
        outtextxy(530, i * 30 + 60, labels[i]);

        start_angle = end_angle;
    }
}

int main()
{
    int gd = DETECT, gm;
    char data[] = "C:\\MinGW\\lib\\libbgi.a"; // static file

    initgraph(&gd, &gm, data);

    // Data for the pie chart (percentages)
    int values[] = {30, 20, 15, 35}; // Modify these values based on your data
    char labels[][20] = {"Income", "Rent", "Groceries", "Other Expenses"};

    int cx = getmaxx() / 2;
    int cy = getmaxy() / 2;
    int radius = 100;

    drawPieChart(cx, cy, radius, values, sizeof(values) / sizeof(values[0]), labels);

    getch();
    closegraph();
    return 0;
}
