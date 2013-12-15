//
// Search for value in sorted array that may have duplicated elements.
//
// @Author: Xin Chen
// @Created on: 4/15/2013
// @Last modified: 4/15/2013
//
#include <iostream>
using namespace std;

//
// Find position of FIRST v in A.
//
int searchDupArrayL(int A[], int n, int v) {
    int L = 0, R = n-1, M, ret = -1;
    
    while (L <= R) {
        M = L + (R-L)/2;
        if (A[M] >= v) {
            ret = M;
            R = M - 1;
        }
        else {
            L = M + 1;
        }
    }
    
    if (ret >= 0 && ret < n && A[ret] == v) {
        cout << "found " << v << " at position " << ret << endl;
        return ret;
    }
    else {
        cout << "not found: " << v << endl;
        return -1;
    }
}

//
// Find position of LAST v in A.
//
int searchDupArrayR(int A[], int n, int v) {
    int L = 0, R = n-1, M, ret = -1;
    
    while (L <= R) {
        M = L + (R-L)/2;
        if (A[M] <= v) {
            ret = M;
            L = M + 1;
        }
        else {
            R = M - 1;
        }
    }
    
    if (ret >= 0 && ret < n && A[ret] == v) {
        cout << "found " << v << " at position " << ret << endl;
        return ret;
    }
    else {
        cout << "not found: " << v << endl;
        return -1;
    }
}


void test() {
    int A[] = {0, 1,1,1, 3};
    int n = sizeof(A) / sizeof(int);
    
    searchDupArrayL(A, n, 0);
    searchDupArrayL(A, n, 1);
    searchDupArrayL(A, n, 2);
    
    searchDupArrayR(A, n, 0);
    searchDupArrayR(A, n, 1);
    searchDupArrayR(A, n, 2);

}

int main() {
    test();
    return 0;
}
