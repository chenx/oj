//
// Given Array A[], A[i] is the position to jump to next. Cycles exist.
// Find the longest cycle.
//
// Assume: A[i] is in [1, n]
//
// Idea: ignore cases where A[i] <= 0 or A[i] > n, since it's position to go to next.
// Label a visited cell by negating it. Go through a cycle until a neg is found.
// Then go to the next cell incrementally until it is not neg.
//
// @Author: Xin Chen
// @Created on: 3/21/2013
// @Last modified: 3/21/2013
//
#include <iostream>
using namespace std;

class Solution {
public:
    void dump (int A[], int n) {
        for (int i = 0; i < n; ++ i) cout << A[i] << " ";
        cout << endl;
    }
    
    int findLargestCycle(int A[], int n) {
        int len = 0, maxlen = 0; // max cycle length.
        
        for (int i = 0; i < n; ) {
            if (A[i] <= 0 || A[i] > n) {
                if (len > maxlen) {
                    maxlen = len;
                    len = 0;
                }
                ++ i;
                continue;
            }
            
            if (i == A[i] - 1) { // self-loop.
                maxlen = max(1, maxlen);
                A[i] = - A[i];
                ++ i;
            }
            else {
                ++ len;
                A[i] = - A[i];
                i = - A[i] - 1; // -1, because A[i] is 1-based.
            }        
        }
        
        return maxlen;
    }
    
    // same as above, but with debug information.
    int findLargestCycle_debug(int A[], int n) {
        int len = 0, maxlen = 0; // max cycle length.
        
        for (int i = 0; i < n; ) {
    cout << "a: i = " << i << " -- "; dump(A, n);
            if (A[i] <= 0 || A[i] > n) {
                if (len > maxlen) {
                    maxlen = len;
                    len = 0;
                }
                ++ i;
    cout << "b: i = " << i << " -- "; dump(A, n);
                continue;
            }
            
            if (i == A[i] - 1) { // self-loop.
                maxlen = max(1, maxlen);
                A[i] = - A[i];
                ++ i;
    cout << "c: i = " << i << " -- "; dump(A, n);
            }
            else {
                ++ len;
                A[i] = - A[i];
                i = - A[i] - 1; 
    cout << "d: i = " << i << " -- "; dump(A, n);
            }        
        }
        
        return maxlen;
    }
};


int main() {
    int A[] = {2,1,6,3,4,3};
    //int A[] = {0,-1,5,3,4,2};
    int n = sizeof(A) / sizeof(int);
    
    Solution s;
    cout << "max cycle length: " << s.findLargestCycle_debug(A, n) << endl;
    
    return 0;
}
