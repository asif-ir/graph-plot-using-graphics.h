#include "Graph.h"
#include <graphics.h>

using namespace std;

int main()
{
    initwindow(1300, 700, "My Plots");

    Graph g("data/points.txt");
    g.plot();

    /*setcolor(YELLOW);
    for (int i = 0; i < counter - 1; ++i) {
        g.drawline(points[i][0], points[i][1], points[i+1][0], points[i+1][1]);
    }
    */
    getch();
}

