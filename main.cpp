#include <fstream> 
#include <string>  
#include <iostream>  
#include "String.h"
#include <search.h> 

//#include "SD.h" 
using namespace std; 
int searching(int n); 
int cheking(); 
int wrote(string str); 
string window(); 
int main() { 
    cout << "Privet hozain, now i work" << endl;
    string sf = window();
    if (sf == "-1") {
        return 0;
    }
    else if (sf != "0") {
        wrote(sf);
    } 
    int countmemory = cheking(); 
    searching(countmemory); 
}
