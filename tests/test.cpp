#include <app_lib/String.h>
#include <app_lib/ctest.h>
#include <app_lib/functions.h>

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
// testing writtingSupportList - algoritm #1/3 "searching"
CTEST(searching, test4)
{
    char mas[] = "{}";
    char* exp = writtingSupportList(mas, 3);
    char real[] = "{}";
    ASSERT_STR(exp, real);
}
CTEST(searching, test5)
{
    char mas[] = "'{'}'['";
    char* exp = writtingSupportList(mas, 8);
    char real[] = "}";
    ASSERT_STR(exp, real);
}
CTEST(searching, test6)
{
    char mas[] = "{[]sry[][]4hgd(){(6))}({)bc}()}jkl[][]}";
    char* exp = writtingSupportList(mas, 40);
    char real[] = "{[][][](){())}({)}()}[][]}";
    ASSERT_STR(exp, real);
}
CTEST(searching, test7)
{
    char mas[] = "";
    char* exp = writtingSupportList(mas, 1);
    char real[] = "";
    ASSERT_STR(exp, real);
}
// testing counting - algoritm #2/3 "searching"
CTEST(searching, test8)
{
    char mas[] = "{}]";
    char* exp = counting(mas, 4);
    char real[] = "00]";
    ASSERT_STR(exp, real);
}
CTEST(searching, test9)
{
    char mas[] = "";
    char* exp = counting(mas, 1);
    char real[] = "";
    ASSERT_STR(exp, real);
}
CTEST(searching, test10)
{
    char mas[] = "{}[]({[)}]";
    char* exp = counting(mas, 11);
    char real[] = "0000000000";
    ASSERT_STR(exp, real);
}
CTEST(searching, test11)
{
    char mas[] = "{qw({}][{)])8){[([]0-}]";
    char* exp = counting(mas, 24);
    char real[] = "0qw000]0{00)8){0(000-00";
    ASSERT_STR(exp, real);
}
// testing counting - algoritm #3/3 "searching"
CTEST(searching, test12)
{
    char mas[] = "000";
    int in[] = {3, 5, 8};
    int expsize = 0;
    unsigned char* exp = promo(mas, in, 4, expsize);
    unsigned char* real = new unsigned char[1];
    int realsize = 1;
    ASSERT_DATA(exp, expsize, real, realsize);
}

CTEST(searching, test13)
{
    char mas[] = "0000001000";
    int in[] = {3, 5, 8, 34, 67, 78, 98, 123, 565, 786};
    int expsize = 0;
    unsigned char* exp = promo(mas, in, 10, expsize);
    unsigned char* real = new unsigned char[10];
    int realsize = 1;
    ASSERT_DATA(exp, expsize, real, realsize);
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
