#include <iostream> 
#include "String.h"
#include <fstream> 
 
using namespace std; 
 
std::string window() { 
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
    case'1':
      cout << "\nВведите полный адрес файла(не забутьте заменить 1'\\' на 2'\\\\' и в конце нажать Enter -> ctlr+x -> Enter для Windows или Enter -> ctlr+d -> Enter) : ";
      while (getline(cin, str)) {
        st = st + str;
      }
      cout << st;
      file.close();
      return st;
    case'2':
      cout << "\nВведите код в консоль(для окончания ввода нажмите Enter -> ctlr+x -> Enter для Windows или Enter -> ctlr+d -> Enter): \n";
      while (getline(cin, st)) {
        file << st << endl;
      }
      file.close();
      return "0";
    case'0':
      return "0";
      break;
    default:
      cout << "\nВвод неверных данных, повторите попытку снова ";
      goto zn;
    } 
 } 
}
