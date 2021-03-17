#include "inputcheck.h"
#include <stdio.h>
int inputcheck(char st[], int borderfigure, int dlina, int index)
{
    int borderx = 0;
    int point = 0;
    for (int i = borderfigure + 1; i < dlina; i++) {
        if ((st[i] >= '0') && (st[i] <= '9')) {
            continue;
        } else {
            if ((st[i] == ',') || ((st[i] == ')') && (index == 3))) {
                borderx = i;
                break;
            }
            if ((st[i] == '.') && (point == 0)) {
                point++;
                continue;
            } else {
                if (index == 1)
                    printf("coord x wrong\n");
                if (index == 2)
                    printf("coor y wrong\n");
                if (index == 3)
                    printf("radius wrong\n");
                while ((st[i] != ',') && (st[i] != ')')) {
                    i++;
                }
                borderx = i;
                break;
            }
        }
    }
    return borderx;
}
