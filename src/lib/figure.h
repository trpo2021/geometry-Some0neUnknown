#ifndef FIGURE_H_
#define FIGURE_H_
#include <stdbool.h>
#define pi 3.14
struct Figure {
    double x_coordinate;
    double y_coordinate;
    double radius;
};
double circle_perimetr(double radius);
double circle_square(double radius);
double* get_input(char inputstring[]);
_Bool are_circles_intercepting();
#endif
