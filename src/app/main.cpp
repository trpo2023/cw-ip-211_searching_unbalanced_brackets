#include "../app_lib/String.h"
#include <fstream>
#include <iostream>
#include <search.h>
#include <string>

//#include "SD.h"
using namespace std;
int searching(int n);
char fille[] = "file.txt";
int cheking(char fille[]);
char* readFile(char fille[]);
int numbersumbols(char fille[]);
int numbersumbols1(char arr[], int cols);
int wrote(string str);
string window();
int main()
{
    cout << "Privet hozain, now i work" << endl;
    string sf = window();
    if (sf == "-1") {
        cout << "Bye Bye" << endl;
        return 0;
    } else if (sf != "0") {
        wrote(sf);
    }
    char* arr = readFile(fille);           // massive vsex simvolov
    int cols = numbersumbols(fille);       // colichestvo vsex simvolov faila
    int cols1 = numbersumbols1(arr, cols); // chislo skobok

    int countmemory = cheking(fille);
    cout << "Quantity '{}[]': " << countmemory << endl;
    searching(countmemory);
}
