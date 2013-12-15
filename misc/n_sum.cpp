//
// http://zhedahht.blog.163.com/blog/static/25411174200732711051101/
// Given integer n, output all consecutive sequences of positive integers
// that sum to n.
//
// @Created on: 3/9/2013
//

#include <iostream>
using namespace std;

void doPrint(int m, int k) {
    for (int i = 0; i <= k; ++ i) {
        cout << m+i << " ";
    }
    cout << endl;
}

void doFind(int n) {
    int m;
    for (int k = 1; k <= n; ++ k) {
        int x = n - k*(k+1)/2;
        if (x <= 0) break;
        if (x % (k+1) == 0) {
            doPrint(x / (k+1), k);
        }
    }
}

int main() {
    doFind(15);
    return 0;
}
