#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/inputcheck.h"


int main()
{
    double x = 0, y = 0, r = 0;
    char inputstring[50];
    fgets(inputstring, 50, stdin);
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
    x = atof(digit);
    int bordery = inputcheck(inputstring, border, dlina, 2);
    for (int i = 0; i < bordery - border; i++) {
        digit[i] = inputstring[border + i + 1];
    }
    y = atof(digit);
    int borderr = inputcheck(inputstring, bordery, dlina, 3);
    for (int i = 0; i < borderr - bordery; i++) {
        digit[i] = inputstring[bordery + i + 1];
    }
    r = atof(digit);
    if (inputstring[borderr + 1] != '\n') {
        printf("Error other symbols");
    }
    printf("%f %f %f\n", x, y, r);
    free(digit);
}


