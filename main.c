#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int correction(char st[], int borderf, int dlina)
{
    int borderx = 0;
    int point = 0;
    for (int i = borderf + 2; i < dlina; i++) {
        if ((st[i] >= '0') && (st[i] <= '9')) {
            continue;
        } else {
            if (st[i] == ',') {
                borderx = i;
                break;
            }
            if ((st[i] == '.') && (point == 0)) {
                point++;
                continue;
            } else {
                printf("coord x wrong\n");
                while (st[i] != ',') {
                    i++;
                }
                borderx = i;
                break;
            }
        }
    }
    return borderx;
}

int rcorrect(char st[], int borderf, int dlina)
{
    int borderx = 0;
    int point = 0;
    for (int i = borderf + 1; i < dlina; i++) {
        if ((st[i] >= '0') && (st[i] <= '9')) {
            continue;
        } else {
            if (st[i] == ')') {
                borderx = i;
                break;
            }
            if ((st[i] == '.') && (point == 0)) {
                point++;
                continue;
            } else {
                printf(" wrong r\n");
                while (st[i] != ')') {
                    i++;
                }
                borderx = i;
                break;
            }
        }
    }
    return borderx;
}
int main()
{
    double x,y,r=0;
    char st[50];
    fgets(st, 50, stdin);
    int dlina = strlen(st);
    int borderf = 0;
    for (int i = 0; i < dlina; i++) {
        if (st[i] == '(') {
            borderf = i;
        }
    }
    if (strncmp(st, "circle", 6) == 0) {
    } else {
        printf("wrong figure\n");
    }
    int border = correction(st, borderf, dlina);
    char* chislo = (char*)calloc((border - borderf - 1), sizeof(char));
    for (int i = 0; i < border - borderf; i++) {
        chislo[i] = st[borderf + i + 1];
    }
    x = atof(chislo);
    int bordery = correction(st, border, dlina);
    for (int i = 0; i < bordery - border; i++) {
        chislo[i] = st[border + i + 1];
    }
    y = atof(chislo);
    int borderr = rcorrect(st, bordery, dlina);
    for (int i = 0; i < borderr - bordery; i++) {
        chislo[i] = st[bordery + i + 1];
    }
    r = atof(chislo);
    if (st[borderr + 1] != '\n') {
        printf("Error other symbols");
    }
    printf("%f %f %f\n", x, y ,r);

}

