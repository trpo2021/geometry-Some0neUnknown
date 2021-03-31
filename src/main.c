#include "lib/figure.h"
#include "lib/inputcheck.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    double x = 0, y = 0, r = 0;
    char inputstring[50];
    fgets(inputstring, 50, stdin);
    double* input = get_input(inputstring);
    x = input[0];
    y = input[1];
    r = input[2];
    printf("%f %f %f\n", x, y, r);
    float perimetr = circle_perimetr(r);
    float square = circle_square(r);
    printf("%f\n", perimetr);
    printf("%f\n", square);
}
