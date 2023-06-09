#include "String.h"
#include "ctest.h"
#include "functions.h"
#include "search.h"
#include <fstream>
#include <iostream>
#include <string>

CTEST(searching, test1)
{
    std::string files = "test1.txt";
    std::string filess = "test1.txt";
    int a = cheking();
    int real = 1;
    int exp = searching(a);
    ASSERT_EQUAL(exp, real);
}
CTEST(searching, test2)
{
    std::string files = "test2.txt";
    std::string filess = "test2.txt";
    int a = cheking();
    int real = 1;
    int exp = searching(a);
    ASSERT_EQUAL(exp, real);
}
CTEST(searching, test3)
{
    std::string files = "test3.txt";
    std::string filess = "test3.txt";
    int a = cheking();
    int real = 1;
    int exp = searching(a);
    ASSERT_EQUAL(exp, real);
}
