#include "ctest.h"
#include "libgeometry/geometry.h"

CTEST(suite, system_testing)
{
    ASSERT_EQUAL(1 + 2, 3);
}

CTEST(figur_name_check, incorrect_name)
{
    char str[2] = {"c"};

    int real = figur_name_check(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(figur_name_check, incorrect_name)
{
    char str[8] = {"8circle"};

    int real = figur_name_check(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(figur_name_check, incorrect_name)
{
    char str[7] = {"Circle"};

    int real = figur_name_check(str);

    int exp = 0;

    ASSERT_EQUAL(exp, real);
}

CTEST(figur_name_check, incorrect_name)
{
    char str[8] = {" Circle"};

    int real = figur_name_check(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(figur_name_check, incorrect_name)
{
    char str[7] = {"circle"};

    int real = figur_name_check(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(data_check, incorrect_data)
{
    char str[9] = {"(0 0, 8)"};

    int s = 1;

    int real = data_check(s, str);

    int exp = 0;

    ASSERT_EQUAL(exp, real);
}

CTEST(data_check, incorrect_data)
{
    char str[10] = {"( 0 0, 8)"};

    int s = 1;

    int real = data_check(s, str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(data_check, incorrect_data)
{
    char str[7] = {"(0, 8)"};

    int s = 1;

    int real = data_check(s, str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(data_check, incorrect_data)
{
    char str[8] = {"(0 0 8)"};

    int s = 1;

    int real = data_check(s, str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(data_check, incorrect_data)
{
    char str[8] = {"(0 0, 8"};

    int s = 1;

    int real = data_check(s, str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}