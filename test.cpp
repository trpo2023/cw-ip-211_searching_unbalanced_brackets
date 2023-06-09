#include "ctest.h"
#include "functions.h"
#include "search.h"
#include "String.h"
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

