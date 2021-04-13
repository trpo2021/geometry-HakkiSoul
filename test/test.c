#include "ctest.h"
#include "libgeometry/geometry.h"

CTEST(suite, system_testing)
{
    ASSERT_EQUAL(1 + 2, 3);
}

CTEST(figur_name_check, incorrect_figure_1)
{
    char str[] = {"c"};

    int real = figur_name_check(&str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(figur_name_check, incorrect_figure_2)
{
    char str[] = {"8circle"};

    int real = figur_name_check(&str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(figur_name_check, incorrect_figure_2)
{
    char str[] = {"Circle"};

    int real = figur_name_check(&str);

    int exp = 0;

    ASSERT_EQUAL(exp, real);
}

CTEST(figur_name_check, incorrect_figure_2)
{
    char str[] = {" Circle"};

    int real = figur_name_check(&str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(figur_name_check, incorrect_figure_2)
{
    char str[] = {"circle"};

    int real = figur_name_check(&str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(data_check, incorrect_figure_2)
{
    char str[] = {"(0 0, 8)"};

    int s = 1;

    int real = data_check(s, &str);

    int exp = 0;

    ASSERT_EQUAL(exp, real);
}

CTEST(data_check, incorrect_figure_2)
{
    char str[] = {"( 0 0, 8)"};

    int s = 1;

    int real = data_check(s, &str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(data_check, incorrect_figure_2)
{
    char str[] = {"(0, 8)"};

    int s = 1;

    int real = data_check(s, &str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(data_check, incorrect_figure_2)
{
    char str[] = {"(0 0 8)"};

    int s = 1;

    int real = data_check(s, &str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(data_check, incorrect_figure_2)
{
    char str[] = {"(0 0, 8"};

    int s = 1;

    int real = data_check(s, &str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}