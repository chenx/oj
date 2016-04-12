#include <iostream>
#include <math.h>
using namespace std;

/*
 * http://www.engr.mun.ca/~theo/Misc/exp_parsing.htm
    E --> T {( "+" | "-" ) T}
    T --> F {( "*" | "/" ) F}
    F --> P ["^" F]
    P --> v | "(" E ")" | "-" T
 */


class Solution2 {
public:
    int calculate(string s) {
        const char *p = s.c_str();
        return E(p);
    }

    void ignoreSpace(const char*& p) { while (isspace(*p)) ++ p; }

    int num(const char*& p) {
        int v = 0;
        while (isdigit(*p)) { v = v * 10 + (*p - '0'); ++ p; }

        return v;
    }

    void expect(const char *& p, char c) {
        if (*p != c) {
            cout << "error: expect: " << c << endl;
            throw exception();
        }
        ++ p;
    }

    int F(const char *& p) {
        int v = P(p);

        if (*p == '^') {
            int e = F(++ p);
            return pow(v, e);
        }

        return v;
    }

    // Note: need to ignoreSpace() both before and after,
    // so use a v and return at the end.
    int P(const char *& p) {
        ignoreSpace(p);

        int v = 0;
        if (*p == '-') {
            v = - T(++ p);
        }
        else if (*p == '(') {
            v = E(++ p);
            expect(p, ')');
        }
        else if (isdigit(*p)) {
            v = num(p);
        }
        else if (! *p) {
            v = 0;
        }
        else {
            cout << "error (F): invalid input: " << p  << endl;
            throw exception();
        }

        ignoreSpace(p);
        return v;
    }

    int T(const char *& p) {
        int v = F(p);

        while (*p == '*' || *p == '/') {
            char op = *p;
            int u = F(++ p);
            if (op == '*') v *= u;
            else if (op == '/') v /= u;
        }
        return v;
    }

    int E(const char *& p) {
        int v = T(p);

        while (*p == '+' || *p == '-') {
            char op = *p;
            int u = T(++ p);
            if (op == '+') v += u;
            else if (op == '-') v -= u;
        }
        return v;
    }
};


/*
 * http://www.engr.mun.ca/~theo/Misc/exp_parsing.htm
    E --> T {( "+" | "-" ) T}
    T --> F {( "*" | "/" ) F}
    F --> num | "(" E ")"
 * Note: F could be: - T
 */
class Solution {
public:
    int calculate(string s) {
        const char *p = s.c_str();
        return E(p);
    }

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

    int F(const char *& p) {
        ignoreSpace(p);

        int v = 0;
        if (*p == '(') {
            v = E(++ p);
            expect(p, ')');
        }
        else if (isdigit(*p)) {
            v = num(p);
        }


    Solution2 so;

    string in[] = {"3 + 4 * 4 - 2", "1 + 3 * (4 / 2 + 6) + 8",
        "1 + 3 * 2^3^2 + 8",
        "4 + - (2 + 3 - 4) + 4", "4 + - (2 + 3 - - 4) * 2"};
    int out[] = {17, 33, 1545, 7, -14};
    int n = sizeof(out) / sizeof(int);

    for (int i = 0; i < n; ++ i) {
        int answer = so.calculate(in[i]);
        cout << "in: " << in[i] << " = " << answer << ", expect: " << out[i]
             << ". " << (answer == out[i] ? "pass" : "fail") << endl;
    }
}

void test1() {
    cout << "test1" << endl;

    Solution so;

    string in[] = {"3 + 4 * 4 - 2", "1 + 3 * (4 / 2 + 6) + 8"};
    int out[] = {17, 33};
    int n = sizeof(out) / sizeof(int);

    for (int i = 0; i < n; ++ i) {
        int answer = so.calculate(in[i]);
        cout << "in: " << in[i] << " = " << answer << ", expect: " << out[i]
             << ". " << (answer == out[i] ? "pass" : "fail") << endl;
    }
}


int main() {
    test1();
    test2();
    return 0;
}
