//
// This works.
//
class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int n = num.size();
        if (n <= 1) return 0;

        int L = 0, R = n - 1;

        while (L <= R) {
            int M = L + (R - L)/2;
            
            if (M == 0 && num[0] > num[M+1]) { return 0; }
            else if (M == n - 1 && num[M] > num[M-1]) { return n - 1; }
            else if (num[M] > num[M-1] && num[M] > num[M+1]) { return M; }
            
            if (num[M] < num[M + 1]) L = M + 1;
            else R = M - 1; // same as: else if (num[M] < num[M - 1]) R = M - 1;
        }
        
        return 0;
    }
};


/**
Find Peak Element 
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

Note:
Your solution should be in logarithmic complexity.
 */
