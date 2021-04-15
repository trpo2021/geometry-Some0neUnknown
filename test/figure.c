#include <ctest.h>
#include <figure.h>

CTEST(figure_suit, square_calculation1)
{
    const double radius = 3.4;

    const double expected = pi * radius * radius;

    const double result = circle_square(radius);
    ASSERT_EQUAL(expected, result);
}

CTEST(figure_suit, square_calculation2)
{
    const double radius = 43.32;

    const double expected = pi * radius * radius;

    const double result = circle_square(radius);
    ASSERT_EQUAL(expected, result);
}

CTEST(figure_suit, square_calculation3)
{
    const double radius = 4123.23;

    const double expected = pi * radius * radius;

    const double result = circle_square(radius);
    ASSERT_EQUAL(expected, result);
}

CTEST(figure_suit, perimeter_calculation1)
{
    const double radius = 3.4;

    const double expected = 2 * pi * radius;

    const double result = circle_perimetr(radius);
    ASSERT_EQUAL(expected, result);
}

CTEST(figure_suit, perimeter_calculation2)
{
    const double radius = 43.22;

    const double expected = 2 * pi * radius;

    const double result = circle_perimetr(radius);
    ASSERT_EQUAL(expected, result);
}

CTEST(figure_suit, perimeter_calculation3)
{
    const double radius = 23.21;

    const double expected = 2 * pi * radius;

    const double result = circle_perimetr(radius);
    ASSERT_EQUAL(expected, result);
}

CTEST(figure_suit, get_input_test1)
{
    char* input = "circle(3,3,3)";
    const int input_length = 3;

    const double expected[] = {3, 3, 3};
    double* result = get_input(input);

    int flag_of_equality = 1;
    for (int i = 0; i < input_length; i++)
        if (expected[i] != result[i]) {
            flag_of_equality = 0;
            break;
        }
    ASSERT_TRUE(flag_of_equality);
}

CTEST(figure_suit, get_input_test2)
{
    char* input = "circle(23,432,41)";
    const int input_length = 3;

    const double expected[] = {23, 432, 41};
    double* result = get_input(input);

    int flag_of_equality = 1;
    for (int i = 0; i < input_length; i++)
        if (expected[i] != result[i]) {
            flag_of_equality = 0;
            break;
        }
    ASSERT_TRUE(flag_of_equality);
}

CTEST(figure_suit, get_input_test3)
{
    char* input = "circle(1,2,333)";
    const int input_length = 3;

    const double expected[] = {1, 2, 333};
    double* result = get_input(input);

    int flag_of_equality = 1;
    for (int i = 0; i < input_length; i++)
        if (expected[i] != result[i]) {
            flag_of_equality = 0;
            break;
        }
    ASSERT_TRUE(flag_of_equality);
}

CTEST(figure_suit, interception_test1)
{
    const struct Figure circle1 = {3, 3, 3};
    const struct Figure circle2 = {3, 3, 43};

    bool result = are_circles_intercepting(circle1, circle2);
    ASSERT_TRUE(result);
}

CTEST(figure_suit, interception_test2)
{
    const struct Figure circle1 = {213, 123, 3};
    const struct Figure circle2 = {3, 3, 12};

    bool result = are_circles_intercepting(circle1, circle2);
    ASSERT_FALSE(result);
}