#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool findThirdDotPosition(const string& filename, int& lineNum, int& posInLine) {
    ifstream file(filename);
    if (!file) {
        cerr << "Could not open file: " << filename << endl;
        return false;
    }

    char ch;
    int dotCount = 0; 
    lineNum = 1;
    posInLine = 0; 

    while (file.get(ch)) {
        if (ch == '\n') {
            ++lineNum;
            posInLine = 0; 
        }
        ++posInLine; 

        if (ch == '.') {
            ++dotCount;
            if (dotCount == 3) {
                return true; 
            }
        }
    }
    return false; 
}

int main() {
    string filename = "t.txt";
    int line, position;

    if (findThirdDotPosition(filename, line, position)) {
        cout << "The third dot is located at line " << line << ", position " << position << "." << endl;
    }
    else {
        cout << "The file does not contain three dots." << endl;
    }

    return 0;
}