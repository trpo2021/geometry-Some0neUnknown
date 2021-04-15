#include <ctest.h>
#include <inputcheck.h>

CTEST(input_check_suit, correct_input_check)
{
    char* input = "circle(23,43,32)";
    int k = 0;
    const int result = inputcheck(input, 0, 17, k);
    ASSERT_TRUE(result);
}