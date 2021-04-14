#include "lib/figure.h"
#include "lib/inputcheck.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Input amount of figures >> ");
    int amount_of_figures;
    char input_amount_of_figures[100];
    fgets(input_amount_of_figures, 100, stdin);
    amount_of_figures = atoi(input_amount_of_figures);
    struct Figure figures[amount_of_figures];
    for (int iterator = 0; iterator < amount_of_figures; iterator++) {
        char inputstring[50];
        fgets(inputstring, 50, stdin);
        double* input = get_input(inputstring);
        figures[iterator].x_coordinate = input[0];
        figures[iterator].y_coordinate = input[1];
        figures[iterator].radius = input[2];
        printf("%f %f %f\n",
               figures[iterator].x_coordinate,
               figures[iterator].y_coordinate,
               figures[iterator].radius);
        float perimetr = circle_perimetr(figures[iterator].radius);
        float square = circle_square(figures[iterator].radius);
        printf("%f\n", perimetr);
        printf("%f\n", square);
    }
    print_all_figures_intersections(figures, amount_of_figures);
}
