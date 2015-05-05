//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/24/2012
// @Last modified: 12/24/2012
//

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 1) return n;        
        
        int v = A[0], k = 0, ct = 1;
        for (int i = 1; i < n; i ++) {
            if (A[i] == v) {
                if (ct == 1) {
                    k ++;
                    if (k < i) A[k] = A[i];
                }
                ct ++;                
            } else {
                v = A[i];
                k ++;
                if (k < i) A[k] = A[i];
                ct = 1;
            } 
        }
                
        return k + 1;
    }    
};

// This works too, slightly better code.

class Solution2 {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 1) return n;        
        
        int v = A[0], k = 1, ct = 1;
        for (int i = 1; i < n; i ++) {
            if (A[i] == v) {
                ++ ct;                
                if (ct == 2) {
                    if (k < i) A[k] = A[i];
                    ++ k;
                }
            } else {
                v = A[i];
                if (k < i) A[k] = A[i];
                ++ k;
                ct = 1;
            } 
        }
                
        return k;
    }    
};


/*
Problem:

Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].

 */