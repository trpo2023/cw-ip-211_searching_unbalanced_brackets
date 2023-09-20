#include "../src/app_lib/String.h"
#include "../src/app_lib/ctest.h"
#include <fstream>
#include <iostream>
int cheking(char fill[]);
int numbersumbols1(char arr[], int cols);
// testing numbersumbols1
CTEST(searching, test1)
{
    char mas[] = "[]]{}}()9]";
    int exp = numbersumbols1(mas, 11);
    int real = 9;
    ASSERT_EQUAL(exp, real);
}

CTEST(searching, test2)
{
    char mas[] = "597gjdie8473yrhbwi4i6nvzxc3215";
    int exp = numbersumbols1(mas, 31);
    int real = 0;
    ASSERT_EQUAL(exp, real);
}
CTEST(searching, test3)
{
    char mas[] = "'{' []";
    int exp = numbersumbols1(mas, 7);
    int real = 2;
    ASSERT_EQUAL(exp, real);
}

/*
CTEST(searching, test3)
{
    char files[] = "cw-ip-211_searching_unbalanced_brackets/test/test3.txt";
    char filess[] = "cw-ip-211_searching_unbalanced_brackets/test/test3.txt";
    int a = cheking();
    int real = 0;
    int exp = searching(a);
    ASSERT_EQUAL(exp, real);
}
*/
