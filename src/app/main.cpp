#include "../app_lib/String.h"
#include <fstream>
#include <iostream>
//#include <search.h>
//#include <string>
using namespace std;
int searching(int n);
char fille[] = "file.txt";
int cheking(char fille[]);
int wrote(string str);
string window(char pok);
char choice();
void window1();
int main()
{
    cout << "Privet hozain, now i work" << endl;
    window1();
    char choicep = choice();
    string sf = window(choicep);
    if (sf == "-1") {
        cout << "Bye Bye" << endl;
        return 0;
    } else if (sf != "0") {
        wrote(sf);
    }
    int countmemory = cheking(fille);
    cout << "Quantity '{}[]': " << countmemory << endl;
    searching(countmemory);
}
