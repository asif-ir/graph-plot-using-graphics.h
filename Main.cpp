#include "Graph.h"
#include <graphics.h>

using namespace std;

int main()
{
    initwindow(800, 600, "Asif & Sameem - Plots");

    Graph g("data/points.txt");

    g.plot();
    getch();

    g.scatter();
    getch();

    closegraph();
}
