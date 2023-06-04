#include <fstream> 
#include <string>  
#include <iostream> 
#include <Windows.h> 
#include <string> 
#include <search.h> 
#include "console.cpp" 
//#include <search.cpp> 
//#include "SD.h" 
using namespace std; 
int searching(int n); 
int cheking(); 
int wrote(string str); 
string window(); 
int main() { 
    cout << "privet hozain, now i work" << endl; 
    string sf = window(); 
    if (sf != "0") { 
        wrote(sf); 
    } 
    int countmemory = cheking(); 
    searching(countmemory); 
}
