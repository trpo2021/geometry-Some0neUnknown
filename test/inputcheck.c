#include <ctest.h>
#include <inputcheck.h>
#include <string.h>

CTEST(input_check_suit, correct_input_check_x)
{
    char* input = "circle(23,43,32)";
    int dlina = strlen(input);
    int borderfigure = 0;
    for (int i = 0; i < dlina; i++) {
        if (input[i] == '(') {
            borderfigure = i;
        }
    }
    const int result = inputcheck(input, borderfigure, dlina, 1);
    ASSERT_EQUAL(9, result);
}

CTEST(input_check_suit, correct_input_check_y)
{
    char* input = "circle(23,43,32)";
    int dlina = strlen(input);
    const int result = inputcheck(input, 9, dlina, 2);
    ASSERT_EQUAL(12, result);
}

CTEST(input_check_suit, correct_input_check_r)
{
    char* input = "circle(23,43,32)";
    int dlina = strlen(input);
    const int result = inputcheck(input, 12, dlina, 3);
    ASSERT_EQUAL(15, result);
}

CTEST(input_check_suit, incorrect_input_check_x)
{
    char* input = "circle(a,43,32)";
    int dlina = strlen(input);
    int borderfigure = 0;
    for (int i = 0; i < dlina; i++) {
        if (input[i] == '(') {
            borderfigure = i;
        }
    }
    const int result = inputcheck(input, borderfigure, dlina, 1);
    ASSERT_EQUAL(-1, result);
}

CTEST(input_check_suit, incorrect_input_check_y)
{
    char* input = "circle(23,a,32)";
    int dlina = strlen(input);
    const int result = inputcheck(input, 9, dlina, 2);
    ASSERT_EQUAL(-2, result);
}

CTEST(input_check_suit, incorrect_input_check_r)
{
    char* input = "circle(23,43,a)";
    int dlina = strlen(input);
    const int result = inputcheck(input, 12, dlina, 3);
    ASSERT_EQUAL(-3, result);
}
CTEST(input_check_suit, incorrect_input_check_x_)
{
    char* input = "circle(+,43,32)";
    int dlina = strlen(input);
    int borderfigure = 0;
    for (int i = 0; i < dlina; i++) {
        if (input[i] == '(') {
            borderfigure = i;
        }
    }
    const int result = inputcheck(input, borderfigure, dlina, 1);
    ASSERT_EQUAL(-1, result);
}
CTEST(input_check_suit, incorrect_input_check_y_)
{
    char* input = "circle(23,=,32)";
    int dlina = strlen(input);
    const int result = inputcheck(input, 9, dlina, 2);
    ASSERT_EQUAL(-2, result);
}

CTEST(input_check_suit, correct_input_check_r_)
{
    char* input = "circle(23,43,-3)";
    int dlina = strlen(input);
    const int result = inputcheck(input, 12, dlina, 3);
    ASSERT_EQUAL(-3, result);
}
