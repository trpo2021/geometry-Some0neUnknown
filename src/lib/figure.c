#include "figure.h"
#include "inputcheck.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
double circle_perimetr(double radius)
{
    return 2 * pi * radius;
}
double circle_square(double radius)
{
    return pi * radius * radius;
}
double* get_input(char inputstring[])
{
    double* array_with_x_y_r = (double*)malloc(3 * sizeof(double));
    int dlina = strlen(inputstring);
    int borderfigure = 0;
    for (int i = 0; i < dlina; i++) {
        if (inputstring[i] == '(') {
            borderfigure = i;
        }
    }
    if (strncmp(inputstring, "circle", 6) == 0) {
    } else {
        printf("wrong figure\n");
    }

    int border = inputcheck(inputstring, borderfigure, dlina, 1);
    char* digit = (char*)calloc((border - borderfigure - 1), sizeof(char));
    for (int i = 0; i < border - borderfigure; i++) {
        digit[i] = inputstring[borderfigure + i + 1];
    }
    array_with_x_y_r[0] = atof(digit);
    int bordery = inputcheck(inputstring, border, dlina, 2);
    for (int i = 0; i < bordery - border; i++) {
        digit[i] = inputstring[border + i + 1];
    }
    array_with_x_y_r[1] = atof(digit);
    int borderr = inputcheck(inputstring, bordery, dlina, 3);
    for (int i = 0; i < borderr - bordery; i++) {
        digit[i] = inputstring[bordery + i + 1];
    }
    array_with_x_y_r[2] = atof(digit);
    if (inputstring[borderr + 1] != '\n') {
        printf("Error other symbols");
    }
    free(digit);
    return array_with_x_y_r;
}
