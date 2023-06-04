#include <fstream>
#include <string> 
#include <iostream>
#include <Windows.h>
#include <string>
#include <search.h>
//#include <search.cpp>
//#include "SD.h"
using namespace std;
int searching( int n);
int cheking();
int wrote();
int main() {
    cout << "privet hozain, now i work" << endl;
    wrote();
    int countmemory = cheking();
    searching(countmemory);
}
