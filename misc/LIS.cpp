/**
 * Find Longest Increasing Sequence in an array.
 * By: XC
 * On: 2/2015
 */

#include <iostream>
#include <vector>
using namespace std;

void dumpVec(vector<int> &v, string name) {
    cout << name << ": ";
    for (int i = 0; i < v.size(); ++ i) cout << v[i] << " ";
    cout << endl;
}

//
// Returns the length of the Longest Increasing Subsequence.
// Also can print out one such LIS sequence (information stored in arrays I and P).
// O(nlog(n)) solution. Uses Patience Sort.
//
int LIS(int A[], int n) {
    if (n <= 1) return n;

    vector<int> B(n); // LIS sequence
    vector<int> I(n); // I[i] is index of B[i] in A.
    vector<int> P(n); // P[i] is index of B[i-1] in A.
    int lenB = 1;
    B[0] = A[0], I[0] = 0, P[0] = -1;

    for (int i = 1; i < n; ++ i) {
        int p = 0, R = lenB - 1;
        while (p <= R) {
            int M = p + (R - p) / 2;
            if (B[M] < A[i]) p = M + 1;
            else R = M - 1;
        }

        // now insert at p.
        cout << "add " << A[i] << " to position " << p << endl;
        B[p] = A[i];
        I[p] = i;
        P[i] = (p == 0) ? -1 : I[p-1]; // NOTE: update P[i] here.
        if (p == lenB) ++ lenB;
    }

    if (1) { // debug
    dumpVec(B, "B");
    dumpVec(I, "I");
    dumpVec(P, "P");

    // give one INC path of maxlen.
    cout << "max LIS length = " << lenB << ": " << endl;
    for (int i = I[lenB - 1]; i >= 0; i = P[i]) { // NOTE: start with I[lenB - 1].
        cout << A[i] << " ";
    }
    cout << endl;
    }

    return lenB;
}


int main() {
    int A[5] = {1,3,4,2,5};
    int n = sizeof(A) / sizeof(int);

    LIS(A, n); //cout << "====================" << endl;

    return 0;
}
