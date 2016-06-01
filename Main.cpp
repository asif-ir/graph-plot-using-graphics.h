#include<stdio.h>
#include<graphics.h>

int points[1000][2];
char *buff;
int counter = 0; // No of points to be plotted, set in constructor.

// Class
class Graph {
    public:
        static const int X_OFFSET = 25;
        static const int Y_OFFSET = 450;

        Graph();
        void init();
        void drawline(int x1, int y1, int x2, int y2);
};

// Constructor
Graph::Graph() {
    FILE *file = fopen("points.txt  ", "r");
    buff = (char*) malloc(255);

    // status reads the number of strings converted by fscanf
    // flip keeps track of 0, 1 position in the array
    char status;
    bool flip = 0;

    do {
        status = fscanf(file, "%s", buff);
        points[counter][flip] = atoi(buff);
        if(flip == 1){
            ++counter;
        }
        flip = !flip;
    }while(status == 1);

    init(); // Draws the axis.
}

void Graph::init() {
   setcolor(CYAN);
   drawline(0, 0, 500, 0);
   drawline(0, 0, 0, 400);
   setcolor(WHITE);
   outtextxy(425, 40, "GRAPH PLOT");
}

void Graph::drawline(int x1, int y1, int x2, int y2) {
    x1 += X_OFFSET;
    y1 = Y_OFFSET - y1;
    x2 += X_OFFSET;
    y2 = Y_OFFSET - y2;
    line(x1, y1, x2, y2);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    Graph g;

    setcolor(YELLOW);
    for (int i = 0; i < counter - 1; ++i) {
        g.drawline(points[i][0], points[i][1], points[i+1][0], points[i+1][1]);
    }
    getch();
}
