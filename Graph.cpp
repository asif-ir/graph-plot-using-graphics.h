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

Graph::Graph(char* data_file, char* x_label, char* y_label){

    this->data_file = data_file;
    this->x_label = x_label;
    this->y_label = y_label;

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

    initwindow(MAX_X, MAX_Y, "Sameem & Asif plots.");
    init();
}

void Graph::init() {
    cleardevice();
    setcolor(CYAN);
    drawline(0, 0, 500, 0);
    drawline(0, 0, 0, 400);
    setcolor(WHITE);
    setLabels(x_label, y_label);

}

void Graph::drawline(int x1, int y1, int x2, int y2) {
    x1 += X_OFFSET;
    y1 = Y_OFFSET - y1;
    x2 += X_OFFSET;
    y2 = Y_OFFSET - y2;
    line(x1, y1, x2, y2);
}
void Graph::xyPlot() {
    init(); // Draws the axis.
    setcolor(WHITE);
    outtextxy(450, 40, "GRAPH PLOT");
    setcolor(YELLOW);
    for (int i = 0; i < counter - 1; ++i) {
        drawline(points[i][0], points[i][1], points[i+1][0], points[i+1][1]);
    }
}

void Graph::drawcircle(int x, int y, int radius) {
    x += X_OFFSET;
    y = Y_OFFSET - y;
    circle(x, y, radius);
}

void Graph::scatterPlotCircle() {
   init(); // Draws the axis.
   setcolor(WHITE);
   outtextxy(425, 40, "SCATTER PLOT CIRCLE");
   setcolor(YELLOW);
   for (int i = 0; i < counter; ++i) {
      drawcircle(points[i][0], points[i][1], 2);
   }
}

void Graph::scatterPlotCross(){
    init(); //Draw axis and set labels
    setcolor(COLOR(255,255,255));
    outtextxy(425, 40, "SCATTER PLOT CROSSES");
    setlinestyle(SOLID_LINE, 1, 2 );
    setcolor(COLOR(174,137,118));

    for (int i = 0; i < counter ; ++i) {
        drawCross(points[i][0], points[i][1]);
    }
    setlinestyle(SOLID_LINE, 1, 1);

}
/*Draw a cross hair at point x1, y1 */
void Graph::drawCross(int x1, int y1){
    /*Need 4 points to draw a cross hair which are calculated from x1, y1*/
    int cross_width = 3;
    drawline(x1 + cross_width, y1 + cross_width, x1 - cross_width , y1 - cross_width);
    drawline(x1 - cross_width, y1 + cross_width, x1 + cross_width, y1 - cross_width);

}
void Graph::setLabels(char* x_label, char* y_label){
    /*Used for setting graph labels
      TODO use variables for off set and padding
    */
    // X axis label
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    settextstyle(0, HORIZ_DIR, 0);
    outtextxy(X_OFFSET + 200, Y_OFFSET + 25, x_label);
    //Y axis label
    settextstyle(0, VERT_DIR, 0);
    outtextxy(X_OFFSET - 25, Y_OFFSET - 150, y_label);
    settextstyle(0, HORIZ_DIR, 0);

}

void Graph:: clear(){
    cleardevice();
}
