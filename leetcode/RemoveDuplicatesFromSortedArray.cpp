//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/24/2012
// @Last modified: 12/24/2012
//

// More efficient, less self-assignment.
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 1) return n;        
        
        int v = A[0], k = 0;
        for (int i = 1; i < n; i ++) {
            if (A[i] != v) {
                v = A[i];
                ++ k;
                if (k < i) A[k] = A[i];
            }
        }
                
        return k + 1;
    }
};


// This works too, and is simpler in code,
// but may have unnecessary self assignments at A[k ++] = A[i].

class Solution2 {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 1) return n;        
        
        int v = A[0], k = 1;
        for (int i = 1; i < n; i ++) {
            if (A[i] != v) {
                v = A[i];
                A[k ++] = A[i];
            }
        }
                
        return k;
    }
};

/**
Remove Duplicates from Sorted Array
Difficulty: Easy

Given a sorted array, remove the duplicates in place such that 
each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this 
in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements 
of nums being 1 and 2 respectively. It doesn't matter what you 
leave beyond the new length. 
 */
