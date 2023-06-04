#include <fstream>
#include <string> 
#include <iostream>
#include <Windows.h>
#include <string>
//#include "SD.h"
using namespace std;

int wrote()
{
    std::string line;
    std::ofstream out;
    std::ifstream in("code.cpp");
    out.open("file.txt");
    if (in.is_open())
    {
        while (std::getline(in, line))
        {
            out << line << std::endl;
        }
    }
    out.close();
    std::cout << "File C++ is writting in file.txt" << std::endl;
    in.close();
    return 0;
}
