#include <ctest.h>
#include <figure.h>

CTEST(figure_suit, square_calculation)
{
    const double radius = 3.4;

    const double expected = pi * radius * radius;

    const double result = circle_square(radius);
    ASSERT_EQUAL(expected, result);
}

CTEST(figure_suit, perimeter_calculation)
{
    const double radius = 3.4;

    const double expected = 2 * pi * radius;

    const double result = circle_perimetr(radius);
    ASSERT_EQUAL(expected, result);
}
