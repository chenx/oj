#include <iostream>
//#include <string> // string.h ok too. // no need.
using namespace std;


// demonstrate breaking a string by delimiters, and keep delimiter info.
void test2() {
    string pattern = " -,.";
    string s = "- This, a sample string.";
    cout << "input: [" << s << "]" << endl;
   
    string w;
    for (int i = 0; i < s.length(); ++ i) {
        string c = s.substr(i, 1);
        if (pattern.find(c) != string::npos) {
            if (w != "") {
                cout << w << endl; // or add to output vector.
                w = "";
            }
            cout << "[" << c << "]" << endl; // or add to output vector.
        }
        else {
            w += c;
        }
    }
}

// demonstrate strtok() function.
// This loses information about delimiter.
void test1() {
    const char * pattern = " -,.";
    string s = "- This, a sample string.";
    char * str = (char *) s.c_str();

    char * p = strtok(str, pattern);
    while (p != NULL) {
        cout << p << endl;
        p = strtok(NULL, pattern);
    }
}

int main() {
    //test1();
    test2();
    return 0;
}
