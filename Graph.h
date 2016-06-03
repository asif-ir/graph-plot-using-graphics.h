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

    public:
        static const int X_OFFSET = 100;
        static const int Y_OFFSET = 450;

        Graph();
        Graph(char*);
        void init();
        void drawline(int x1, int y1, int x2, int y2);
        void plot();
        void scatter();
        void drawcircle(int, int, int);
};


#endif // GRAPH_H_INCLUDED
