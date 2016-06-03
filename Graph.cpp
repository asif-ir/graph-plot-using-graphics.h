#include "Graph.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <string>

// Constructor
Graph::Graph() {
    counter = 0;
    FILE *file = fopen("data/points.txt", "r");
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
//Testing new constructor.

Graph::Graph(char* data_file){
    counter = 0; // No of points to be plotted, set in constructor.

    FILE *file = fopen(data_file , "r");
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
}

void Graph::init() {
   cleardevice();
   setcolor(CYAN);
   drawline(0, 0, 500, 0);
   drawline(0, 0, 0, 400);
}

void Graph::drawline(int x1, int y1, int x2, int y2) {
    x1 += X_OFFSET;
    y1 = Y_OFFSET - y1;
    x2 += X_OFFSET;
    y2 = Y_OFFSET - y2;
    line(x1, y1, x2, y2);
}

void Graph::drawcircle(int x, int y, int radius) {
    x += X_OFFSET;
    y = Y_OFFSET - y;
    circle(x, y, radius);
}

void Graph::plot() {
    init(); // Draws the axis.
    setcolor(WHITE);
    outtextxy(450, 40, "GRAPH PLOT");
    setcolor(YELLOW);
    for (int i = 0; i < counter - 1; ++i) {
        drawline(points[i][0], points[i][1], points[i+1][0], points[i+1][1]);
    }
}

void Graph::scatter() {
   init(); // Draws the axis.
   setcolor(WHITE);
   outtextxy(425, 40, "SCATTER PLOT");
   setcolor(YELLOW);
   for (int i = 0; i < counter; ++i) {
      drawcircle(points[i][0], points[i][1], 2);
   }
}
