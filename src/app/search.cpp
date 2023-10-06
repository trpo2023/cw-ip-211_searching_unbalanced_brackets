#include <app_lib/String.h>
#include <app_lib/functions.h>
#include <fstream>
#include <iostream>
using namespace std;

char* readFile(char files[])
{
    char ch;
    FILE* pf;
    pf = fopen(files, "r");
    int count = 0;
    while ((ch = getc(pf) != EOF)) {
        count++;
    }

    rewind(pf);
    char* chh = new char[count];
    int i = 0;
    while ((ch = getc(pf) != EOF)) {
        chh[i] = ch;
        i++;
    }
    fclose(pf);
    return chh;
}
/*This is a special function for test coverage based on the main algorithm of
 * the "checking" function. It is here that edits are made first and, with
 * successful tests, the algorithm in the “checking” function is changed.
 */
int numbersumbols1(char* chh, int cols)
{
    int count = 0;
    int ch;
    int ct = 0;
    int ct1 = 0;
    for (int i = 0; i < cols; i++) {
        ch = chh[i];
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
    return count;
}

int cheking(char files[])
{
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
    file.close();
    return count;
}
/*This is a special function for test coverage based on the main algorithm of
 * the "searching" function. It is here that edits are made first and, with
 * successful tests, the algorithm in the “searching” function is changed.
 */
char* writtingSupportList(char* arr, int count)
{
    char ch;
    int chetstr = 0;
    int chet = 0;
    int ct = 0;
    int ct1 = 0;
    char* Skobki = new char[count];
    // counting brackets not contained between the characters " and '
    for (int i = 0; i < count; i++) {
        ch = arr[i];
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
            chet++;
        }
        if (ch == '}' and ct == 0 and ct1 == 0) {
            Skobki[chet] = '}';
            chet++;
        }
        if (ch == '[' and ct == 0 and ct1 == 0) {
            Skobki[chet] = '[';
            chet++;
        }
        if (ch == ']' and ct == 0 and ct1 == 0) {
            Skobki[chet] = ']';
            chet++;
        }
        if (ch == '(' and ct == 0 and ct1 == 0) {
            Skobki[chet] = '(';
            chet++;
        }
        if (ch == ')' and ct == 0 and ct1 == 0) {
            Skobki[chet] = ')';
            chet++;
        }
    }
    return Skobki;
}
/*This is a special function for test coverage based on the main algorithm of
 * the "searching" function. It is here that edits are made first and, with
 * successful tests, the algorithm in the “searching” function is changed.
 */
char* counting(char* arr, int count)
{
    for (int i = 0; i < count - 1; i++) {
        for (int j = i; j < count; j++) {
            if (arr[i] != '0') {
                if (arr[i] == '{' and arr[j] == '}') {
                    arr[i] = '0';
                    arr[j] = '0';
                    break;
                }
                if (arr[i] == '[' and arr[j] == ']') {
                    arr[i] = '0';
                    arr[j] = '0';
                    break;
                }
                if (arr[i] == '(' and arr[j] == ')') {
                    arr[i] = '0';
                    arr[j] = '0';
                    break;
                }
            }
        }
    }
    return arr;
}
/*This is a special function for test coverage based on the main algorithm of
 * the "searching" function. It is here that edits are made first and, with
 * successful tests, the algorithm in the “searching” function is changed.
 */
unsigned char* promo(char* arr, int* ind, int count, int& chetTrue)
{
    unsigned char* answer = new unsigned char[count];
    for (int i = 0; i < count; i++) {
        if (arr[i] != '0') {
            chetTrue++;
            answer[chetTrue] = ind[i];
        }
    }
    return answer;
}

int searching(int n)
{
    char filess[] = "file.txt";
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
            if (chetTrue == 1) {
                cout << "Your code is bad" << endl;
            }
            cout << "Bad line:" << indexi[i] << endl;
        }
    }
    if (chetTrue == 0) {
        cout << "Your code is good" << endl;
    }
    file.close();
    return 0;
}
