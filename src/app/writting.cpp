#include <app_lib/String.h>
#include <app_lib/functions.h>
#include <fstream>
#include <iostream>
// the file should not be modified!!!!!

using namespace std;

int wrote(string str)
{
    std::string line;
    std::ofstream out;
    std::ifstream in(str);
    out.open("file.txt");
    if (in.is_open()) {
        while (std::getline(in, line)) {
            out << line << std::endl;
        }
    }
    out.close();
    std::cout << "File C++ is writting in file.txt" << std::endl;
    in.close();
    return 0;
}
