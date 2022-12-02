#include <stdio.h>
#include <math.h>

struct Point{
    double x;
    double y;
};

typedef struct Point Point;

void printPoint (Point p);
Point createPoint (double x, double y);
double getDistance(Point a, Point b);
int main() {
    Point p1= createPoint(2.0, -3.0);
    Point p2= createPoint (-4.0, 5.0);
    printPoint(p1);
    printPoint(p2);
    printf("Atstumas: %.3lf\n", getDistance(createPoint(2.0, -3.0), createPoint (-4.0, 5.0)));
    return 0;
}
void printPoint (Point p){
    printf("Tasko koordinates: (%.2lf,%.2lf)\n", p.x, p.y);
}
Point createPoint (double x, double y){
    Point temp;
    temp.x=x;
    temp.y=y;
    return temp;
}
double getDistance(Point a, Point b){
    return sqrt(pow((a.x-b.x), 2.0)+pow((a.y-b.y), 2.0));
}