class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A) {
        int n = A.size();
        if (n == 0) return -1;
        if (n == 1) return 0;
        if (n == 2) return (A[0] > A[1] ? 0 : 1);
        
        int L = 0, R = n - 1;
        while (L <= R) {
            int M = L + (R - L)/2;
            
            if (M == 0 && A[0] > A[1]) return 0;
            else if (M == n-1 && A[n-1] > A[n-2]) return n-1;
            else if (A[M] > A[M-1] && A[M] > A[M+1]) return M;
            
            if (A[M] < A[M+1]) L = M + 1;
            else R = M - 1;
        }
        
        return -1;
    }
};


/**
Find Peak Element

There is an integer array which has the following features:

    The numbers in adjacent positions are different.
    A[0] < A[1] && A[A.length - 2] > A[A.length - 1].

We define a position P is a peek if:

A[P] > A[P-1] && A[P] > A[P+1]

Find a peak element in this array. Return the index of the peak.
Have you met this question in a real interview?
Notice

The array may contains multiple peeks, find any of them.
Example

Given [1, 2, 1, 3, 4, 5, 7, 6]

Return index 1 (which is number 2) or 6 (which is number 7)
Challenge

Time complexity O(logN)

 */
