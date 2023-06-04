#include <iostream> 
#include <string> 
#include <fstream> 
 
using namespace std; 
 
string window() { 
 setlocale(LC_ALL, "RUS"); 
 char ch; 
 string st; 
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
   cout << "\nВведите полный адрес файла : "; 
   cin >> st; 
   file.close(); 
   return st; 
  case'2': 
   cout << "\nВведите код в консоль(для окончания ввода нажмите 'cntl+z'): \n"; 
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
