#include <app_lib/String.h>
#include <app_lib/functions.h>
#include <fstream>
#include <iostream>
using namespace std;
std::string window(char pok);
int wrote(string str);
int main()
{
    char fille[] = "file.txt";
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
    remove("file.txt");
}
