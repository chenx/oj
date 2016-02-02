// This works too.
class Solution3 {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size(), L = 0, R = n - 1, M;
        
        while (L <= R) {
            M = L + (R - L)/2;
            if (M == 0 && nums[0] > nums[1]) return 0;
            else if (M == n-1 && nums[n-1] > nums[n-2]) return n-1;
            else if (nums[M-1] < nums[M] && nums[M] > nums[M+1]) return M;
            
            if (M > 0 && nums[M-1] > nums[M]) R = M - 1;
            else L = M + 1;
        }
        
        return 0; // "return R;" works too.
    }
};

// This works.
class Solution2 {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int L = 0, R = n - 1;

        while (L <= R) {
            int M = L + (R - L)/2;
            
            if (M == 0) { if (nums[0] > nums[M+1]) return 0; }
            else if (M == n - 1) { if (nums[M] > nums[M-1]) return n - 1; }
            else if (nums[M] > nums[M-1] && nums[M] > nums[M+1]) { return M; }
            
            if (M < n - 1 && nums[M] < nums[M + 1]) L = M + 1;
            else R = M - 1; // same as: else if (num[M] < num[M - 1]) R = M - 1;
            
            // This works too. 
            //if (M > 0 && nums[M] < nums[M - 1]) R = M - 1;
            //else L = M + 1;
        }
        
        return 0;        
    }
};

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
            
            if (M < n - 1 && num[M] < num[M + 1]) L = M + 1;
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
