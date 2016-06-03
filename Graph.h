#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

/*TODO make these members.
extern int points[1000][2];
extern char *buff;
extern int counter; // No of points to be plotted, set in constructor.
*/

class Graph {
    protected:
        int points[1000][2];
        char *buff;
        int counter; // No of points to be plotted, set in constructor.
        /* Axis labels for scatter and xy plots */
        char* x_label;
        char* y_label;
        char* data_file;

    public:
        static const int X_OFFSET = 75;
        static const int Y_OFFSET = 500;
        //Size of window.
        static const int MAX_X  = 800;
        static const int MAX_Y  = 600;

        Graph();
        Graph(char* file_path, char* x_label, char* y_label);
        void init();
        void drawline(int x1, int y1, int x2, int y2);
        void xyPlot();
        void scatterPlotCircle();
        void drawcircle(int, int, int);
        void Graph::drawCross(int x1, int y1);
        void Graph::scatterPlotCross();
        void setLabels(char* x_label, char* y_label);
        void clear();

};


#endif // GRAPH_H_INCLUDED
