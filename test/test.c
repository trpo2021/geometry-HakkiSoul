#include "ctest.h"
#include "libgeometry/geometry.h"

CTEST(suite, system_testing)
{
    ASSERT_EQUAL(1 + 2, 3);
}

CTEST(name_check, part_of_name)
{
    char str[2] = {"c"};

    int real = figur_name_check(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(name_check, empty_name)
{
    char str[1] = {""};

    int real = figur_name_check(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(name_check, incorrect_name)
{
    char str[8] = {"8circle"};

    int real = figur_name_check(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(name_check, incorrect_name_2)
{
    char str[8] = {"Cicle"};

    int real = figur_name_check(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(name_check, incorrect_name_3)
{
    char str[8] = {"Circl"};

    int real = figur_name_check(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(name_check, incorrect_name_4)
{
    char str[8] = {"Oval"};

    int real = figur_name_check(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(name_check, correct_name)
{
    char str[7] = {"Circle"};

    int real = figur_name_check(str);

    int exp = 0;

    ASSERT_EQUAL(exp, real);
}

CTEST(name_check, space_error)
{
    char str[8] = {" Circle"};

    int real = figur_name_check(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(name_check, space_error_2)
{
    char str[8] = {"C ircle"};

    int real = figur_name_check(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(name_check, space_error_3)
{
    char str[8] = {"Cir cle"};

    int real = figur_name_check(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(name_check, small_letter)
{
    char str[7] = {"circle"};

    int real = figur_name_check(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(datacheck, empty_data)
{
    char str[9] = {""};

    int s = 1;

    int real = data_check(s, str);

    int exp = 3;

    ASSERT_EQUAL(exp, real);
}

CTEST(datacheck, empty_data_2)
{
    char str[9] = {"()"};

    int s = 1;

    int real = data_check(s, str);

    int exp = 3;

    ASSERT_EQUAL(exp, real);
}

CTEST(datacheck, correct_data)
{
    char str[9] = {"(0 0, 8)"};

    int s = 1;

    int real = data_check(s, str);

    int exp = 0;

    ASSERT_EQUAL(exp, real);
}

CTEST(datacheck, incorrect_data_space)
{
    char str[10] = {"( 0 0, 8)"};

    int s = 1;

    int real = data_check(s, str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(datacheck, incorrect_data_space_2)
{
    char str[10] = {" (0 0, 8)"};

    int s = 1;

    int real = data_check(s, str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(datacheck, incorrect_data_lost_number)
{
    char str[7] = {"(0, 8)"};

    int s = 1;

    int real = data_check(s, str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(datacheck, incorrect_data_comma)
{
    char str[8] = {"(0 0 8)"};

    int s = 1;

    int real = data_check(s, str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(datacheck, incorrect_data_comma_2)
{
    char str[9] = {"(0 0 ,8)"};

    int s = 1;

    int real = data_check(s, str);

    int exp = 2;

    ASSERT_EQUAL(exp, real);
}

CTEST(datacheck, incorrect_data_comma_3)
{
    char str[10] = {"(0, 0, 8)"};

    int s = 1;

    int real = data_check(s, str);

    int exp = 2;

    ASSERT_EQUAL(exp, real);
}

CTEST(datacheck, incorrect_data_bracket)
{
    char str[8] = {"(0 0, 8"};

    int s = 1;

    int real = data_check(s, str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(datacheck, incorrect_data_bracket_2)
{
    char str[8] = {"0 0, 8)"};

    int s = 1;

    int real = data_check(s, str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(datacheck, incorrect_data_minus)
{
    char str[10] = {"(-0 0, 8)"};

    int s = 1;

    int real = data_check(s, str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}