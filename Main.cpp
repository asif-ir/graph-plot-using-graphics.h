#include "Graph.h"
#include <graphics.h>

using namespace std;

int main()
{
    char* file_path = "data/points.txt";
    char* x_label = "YEAR";
    char* y_label = "POPULATION";

    Graph g(file_path, x_label, y_label);


    g.xyPlot();
    getch();

    g.scatterPlotCircle();
    getch();

    g.scatterPlotCross();
    getch();

    closegraph();
    return 0;
}
