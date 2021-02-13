#include <stdio.h>
#include <stdlib.h>
float const P = 3.1415;
int main()
{
    float x = 0, y = 0, r = 0, per = 0, S = 0;
    printf("Введите данные\n");
    scanf("%f", &x);
    scanf("%f", &y);
    scanf("%f", &r);
    per = 2 * P * r;
    S = P * r * r;
    printf("периметр=%f\n", per);
    printf("площадь=%f\n", S);
}

