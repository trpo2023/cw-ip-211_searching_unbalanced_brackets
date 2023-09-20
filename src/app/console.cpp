#include "../app_lib/String.h"
#include <fstream>
#include <iostream>
//#include <string>

using namespace std;
void window1()
{
    cout << "\nМеню :";
    cout << "\nВведите 1 для ввода полного адреса файла ";
    cout << "\nВведите 2 для ввода кода в консоль ";
    cout << "\nВведите 0 для выхода из программы\n";
}
char choice()
{
    char ch;
    cin >> ch;
    if (ch != '0' and ch != '1' and ch != '2') {
        cout << "\nВвод неверных данных, повторите попытку снова ";
        choice();
    } else {
        return ch;
    }
}
string window(char pok)
{
    string st;
    string str;
    ofstream file("file.txt");
    if (pok == '1') {
        cout << "\nВведите полный адрес файла(не забутьте заменить 1'\\' "
                "на 2'\\\\' и в конце нажать Enter -> ctlr+x -> Enter для "
                "Windows или Enter -> ctlr+d -> Enter) : ";
        while (getline(cin, str)) {
            st = st + str;
        }
        cout << st;
        file.close();
        return st;
    }
    if (pok == '2') {
        cout << "\nВведите код в консоль(для окончания ввода нажмите Enter "
                "-> ctlr+x -> Enter для Windows или Enter -> ctlr+d -> "
                "Enter): \n";
        while (getline(cin, st)) {
            file << st << endl;
        }
        file.close();
        return "0";
    }
    if (pok == '0') {
        return "-1";
    }
}
/*
string window()
{
    setlocale(LC_ALL, "RUS");
    char ch;
    string st;
    string str;
    ofstream file("file.txt");
    while (1) {
        cout << "\nМеню :";
        cout << "\nВведите 1 для ввода полного адреса файла ";
        cout << "\nВведите 2 для ввода кода в консоль ";
        cout << "\nВведите 0 для выхода из программы\n";
    zn:
        cin >> ch;
        switch (ch) {
        case '1':
            cout << "\nВведите полный адрес файла(не забутьте заменить 1'\\' "
                    "на 2'\\\\' и в конце нажать Enter -> ctlr+x -> Enter для "
                    "Windows или Enter -> ctlr+d -> Enter) : ";
            while (getline(cin, str)) {
                st = st + str;
            }
            cout << st;
            file.close();
            return st;
        case '2':
            cout << "\nВведите код в консоль(для окончания ввода нажмите Enter "
                    "-> ctlr+x -> Enter для Windows или Enter -> ctlr+d -> "
                    "Enter): \n";
            while (getline(cin, st)) {
                file << st << endl;
            }
            file.close();
            return "0";
        case '0':
            return "-1";
            break;
        default:
            cout << "\nВвод неверных данных, повторите попытку снова ";
            goto zn;
        }
    }
}
*/
