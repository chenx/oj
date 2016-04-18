//
// Solve 1 variable linear equation.
// Input is right side of equation, left side is always 0.
// E.g., input is: 3*x + 1, then equation is 3*x + 1 = 0
// Idea is to use an array for the co-efficients.
// This can easily be extended to more variables and higher degree (quadratic, ...).
//
// A recursive descent parser is easy to write by hand. It could be O(k^n) in worst case,
// where k is input size. It is a direct implementation of PEG (Parser Expression Grammar).
// 
// From [2]: RD parsers are the most general form of top-down parsing, and the most popular 
// type of parsers to write by hand. However, being so general, they have several problems,
// like requiring backtracking (which is difficult to code correctly and efficiently).
//
// A LL(k) parser is a subclass of recursive descent parser, that requires k lookahead,
// and is more efficient. LL(1) is linear in time O(k). LL(k) parsers are called predictive.
// A predictive parser is a recursive descent parser that does not require backtracking. 
//
// References:
// [1] https://en.wikipedia.org/wiki/Recursive_descent_parser
// [2] http://eli.thegreenplace.net/2008/09/26/recursive-descent-ll-and-predictive-parsers/
// [3] http://stackoverflow.com/questions/1044600/difference-between-an-ll-and-recursive-descent-parser
//
// By: X.C. 4/17/2016
// 

#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>
using namespace std;


string to_string(int n) {
    stringstream ss;
    ss << n;
    return ss.str();
}

/*
 * http://www.engr.mun.ca/~theo/Misc/exp_parsing.htm
    E --> T {( "+" | "-" ) T}
    T --> F {( "*" | "/" ) F}
    F --> num | "(" E ")"
 * Note: F could be: - T
 */
class Solution {
public:
    double calculate(string s) {
        const char *p = s.c_str();
        vector<int> v = E(p); // v(a, c): ax + c = 0;
        cout << "simplified form: " << dump(v) << endl;
        return v[1] == 0 ? 0 : (- 1.0 * v[0] / v[1]);
    }

    char nextChar(const char * p) { while (isspace(*p)) ++ p; return *p; }
    void ignoreSpace(const char*& p) { while (isspace(*p)) ++ p; }
    void expect(const char *& p, char c) {
        if (*p != c) {
            cout << "error: expect: " << c << endl;
            throw exception();
        }
        ++ p;
    }

    int num(const char*& p) {
        int v = 0;
        while (isdigit(*p)) { v = v * 10 + (*p - '0'); ++ p; }
        return v;
    }

    vector<int> F(const char *& p) {
        ignoreSpace(p);

        vector<int> v(2, 0);
        if (*p == '(') {
            v = E(++ p);
            expect(p, ')');
        }
        else if (isdigit(*p)) {
            v[0] = num(p);
        }
        else if (*p == 'x') {
            v[1] = 1;
            ++ p; // don't forget this!
        }
        else if (! *p) { // useful for situation such as input is "".
            v[0] = 0;
        }
        else {
            cout << "F: invalid input: " << p  << endl;
            throw exception();
        }

        ignoreSpace(p);
        return v;
    }

    vector<int> T(const char *& p) {
        vector<int> v = F(p);

        char c = nextChar(p);
        while (c == '*' || c == '/' || c == 'x' || c == '(') {
            if (c == '*') v = mul(v, F(++ p));
            else if (c == 'x' || c == '(') v = mul(v, F(p));
            else v = div(v, F(++ p));
            
            c = nextChar(p); // get next char.
        }
        return v;
    }

    vector<int> E(const char *& p) {
        vector<int> v = T(p);

        while (*p == '+' || *p == '-') {
            if (*p == '+') v = add(v, T(++ p));
            else v = sub(v, T(++ p));
        }
        return v;
    }

    vector<int> add(vector<int> & a, vector<int> b) {
        a[0] += b[0], a[1] += b[1];
        return a;
    }
    vector<int> sub(vector<int> & a, vector<int> b) {
        a[0] -= b[0], a[1] -= b[1];
        return a;
    }
    // mul() assumption: at most one contains x.
    vector<int> mul(vector<int> & a, vector<int> b) {
        a[1] = a[0] * b[1] + a[1] * b[0];
        a[0] = a[0] * b[0];
        return a;
    }
    // div() assumption: b is always a number.
    vector<int> div(vector<int> & a, vector<int> b) {
        a[0] /= b[0], a[1] /= b[0];
        return a;
    }


    string dump(vector<int> & v) {
        string s;
        if (v[1] != 0) s = to_string(v[1]) + "x";
        if (v[0] != 0) {
            if (s == "") s = to_string(v[0]);
            else s += " + " + to_string(v[0]);
        }
        return s;
    }
};



void test1() {
    cout << "test1" << endl;

    Solution so;

    string in[] = {"2 * x - 4", "3 * x + 4 * 4 - 1", "x + 3 * (4 / 2 + 6 * x) + 32", "3 x - 3",
        "3x(3+2) + 15", "(3-1)*(2*(3-1) + x(2 + 2)) - 16 ", "x(2) - 6" };
    int out[] = {2, -5, -2, 1, -1, 1, 3};
    int n = sizeof(out) / sizeof(int);

    for (int i = 0; i < n; ++ i) {
        double answer = so.calculate(in[i]);
        cout << "in: " << in[i] << " = 0. x = " << answer << ". expect: " << out[i] << endl;
        cout << "" << (answer == out[i] ? "pass" : "fail") << endl << endl;
    }
}


int main() {
    test1();
    return 0;
}
