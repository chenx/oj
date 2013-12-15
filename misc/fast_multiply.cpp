//
// Multiply 2 integers m, n in log(n) time.
//
// @Author: Xin Chen
// @Created on: 4/7/2013
// @Last modified: 4/7/2013
//
#include <iostream>
using namespace std;

int mul(int m, int n) {
    if (n < 0) m = -m;

    int R = 0, F = m;

    while (n > 0) {
        if (n & 1) R += F;
        F += F;
        n >>= 1;
    }

    return R;
}

int main() {
    int m = 6, n = 5;
    cout << "mul(" << m << ", " << n << ") = " << mul(m, n) << endl;
    return 0;
}