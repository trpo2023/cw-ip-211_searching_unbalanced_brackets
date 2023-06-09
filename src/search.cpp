#include "String.h"
#include <fstream>
#include <iostream>
#include <string>
//#include "SD.h"
using namespace std;
int cheking()
{
    std::string files="file.txt";
    ifstream file(files); // opening a file

    if (!file.is_open()) {
        cerr << "file can't be open" << endl;
        return 1;
    }

    int count = 0;
    char ch;
    //  "{"
    int ct = 0;
    int ct1 = 0;
    // counting brackets not contained between the characters " and '
    while (file.get(ch)) {
        // Checking for the closeness of quotation marks
        if (ch == char(0x22)) {
            if (ct1 == 0)
                ct1++;
            else {
                ct1 = 0;
            }
        }
        if (ch == char(0x27)) {
            if (ct == 0)
                ct++;
            else {
                ct = 0;
            }
        }
        // Searching for brackets and entering them into the Skobki array
        if (ch == '{' and ct == 0 and ct1 == 0) {
            count++;
        }
        if (ch == '}' and ct == 0 and ct1 == 0) {
            count++;
        }
        if (ch == '[' and ct == 0 and ct1 == 0) {
            count++;
        }
        if (ch == ']' and ct == 0 and ct1 == 0) {
            count++;
        }
        if (ch == '(' and ct == 0 and ct1 == 0) {
            count++;
        }
        if (ch == ')' and ct == 0 and ct1 == 0) {
            count++;
        }
    }
    cout << "Quantity '{}[]': " << count << endl;

    file.close();
    return count;
}

int searching(int n)
{
    std::string filess;
    ifstream file(filess); // opening a file

    if (!file.is_open()) {
        cerr << "file can't be open" << endl;
        return 1;
    }
    char ch;
    //  "{"
    int chetstr = 0;
    int chet = 0;
    int ct = 0;
    int ct1 = 0;
    // counting brackets not contained between the characters " and '

    string line;
    char* Skobki = new char[n];
    int* indexi = new int[n];
    while (file.get(ch)) {
        // Checking for the closeness of quotation marks
        if (ch == char(0x22)) {
            if (ct1 == 0)
                ct1++;
            else {
                ct1 = 0;
            }
        }
        if (ch == char(0x27)) {
            if (ct == 0)
                ct++;
            else {
                ct = 0;
            }
        }
        if (ch == '\n') {
            ++chetstr;
        }
        if (ch == '{' and ct == 0 and ct1 == 0) {
            Skobki[chet] = '{';
            indexi[chet] = chetstr;
            chet++;
        }
        if (ch == '}' and ct == 0 and ct1 == 0) {
            Skobki[chet] = '}';
            indexi[chet] = chetstr;
            chet++;
        }
        if (ch == '[' and ct == 0 and ct1 == 0) {
            Skobki[chet] = '[';
            indexi[chet] = chetstr;
            chet++;
        }
        if (ch == ']' and ct == 0 and ct1 == 0) {
            Skobki[chet] = ']';
            indexi[chet] = chetstr;
            chet++;
        }
        if (ch == '(' and ct == 0 and ct1 == 0) {
            Skobki[chet] = '(';
            indexi[chet] = chetstr;
            chet++;
        }
        if (ch == ')' and ct == 0 and ct1 == 0) {
            Skobki[chet] = ')';
            indexi[chet] = chetstr;
            chet++;
        }
    }
    // Search for paired brackets and their pairwise removal from the Skobki
    // array
    for (int i = 0; i < n - 1; i++) {
        for (int j = i; j < n; j++) {
            if (Skobki[i] != '0') {
                if (Skobki[i] == '{' and Skobki[j] == '}') {
                    Skobki[i] = '0';
                    Skobki[j] = '0';
                    break;
                }
                if (Skobki[i] == '[' and Skobki[j] == ']') {
                    Skobki[i] = '0';
                    Skobki[j] = '0';
                    break;
                }
                if (Skobki[i] == '(' and Skobki[j] == ')') {
                    Skobki[i] = '0';
                    Skobki[j] = '0';
                    break;
                }
            }
        }
    }
    int chetTrue = 0;
    for (int i = 0; i < n; i++) {
        if (Skobki[i] != '0') {
            chetTrue++;
            if (chetTrue == 1)
                cout << "Your code is bad" << endl;
            cout << "Bad line:" << indexi[i] << endl;
        }
    }
    if (chetTrue == 0)
        cout << "Your code is good" << endl;
    file.close();
    return chetTrue;
}

