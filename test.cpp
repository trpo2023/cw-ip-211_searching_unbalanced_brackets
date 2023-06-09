#include "ctest.h"
#include <fstream>
#include <iostream>
#include "string.h"
#include "functions.h"
#include "search.h"
CTEST(searching,test1){
	std::string files="test1.txt";
	std::string filess="test1.txt";
	int a=cheking();
	int real=1;
	int exp=searching(a);
	ASSERT_EQUAL(exp, real);
}

