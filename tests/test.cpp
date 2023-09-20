#include "String.h"
#include "ctest.h"
#include "functions.h"
#include "search.h"
#include <fstream>
#include <iostream>
#include <string>

CTEST(searching, test1)
{
    char files[] = "cw-ip-211_searching_unbalanced_brackets/test/test1.txt";
    char filess[] = "cw-ip-211_searching_unbalanced_brackets/test/test1.txt";
    int a = cheking();
    int real = 0;
    int exp = searching(a);
    ASSERT_EQUAL(exp, real);
}
CTEST(searching, test2)
{
    char files[] = "cw-ip-211_searching_unbalanced_brackets/test/test2.txt";
    char filess[] = "cw-ip-211_searching_unbalanced_brackets/test/test2.txt";
    int a = cheking();
    int real = 0;
    int exp = searching(a);
    ASSERT_EQUAL(exp, real);
}
CTEST(searching, test3)
{
    char files[] = "cw-ip-211_searching_unbalanced_brackets/test/test3.txt";
    char filess[] = "cw-ip-211_searching_unbalanced_brackets/test/test3.txt";
    int a = cheking();
    int real = 0;
    int exp = searching(a);
    ASSERT_EQUAL(exp, real);
}
