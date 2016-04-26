// Works too.
class Solution3 {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        vector<int> A(n, 0), B(n, 0);
        
        A[1] = nums[0];
        B[1] = nums[1];
        for (int i = 2; i < n; ++ i) {
            A[i] = max(A[i-1], nums[i-1] + A[i-2]);
            B[i] = max(B[i-1], nums[i]   + B[i-2]);
        }
        
        return max(A[n-1], B[n-1]);
    }
};

// This works too. 1/23/2016.
class Solution2 {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        vector<int> v1(n);
        v1[0] = 0;
        v1[1] = nums[0];
        for (int i = 2; i < n; ++ i) {
            v1[i] = max(v1[i-1], v1[i-2] + nums[i-1]);
        }
        
        vector<int> v2(n);
        v2[0] = 0;
        v2[1] = nums[1];
        for (int i = 2; i < n; ++ i) {
            v2[i] = max(v2[i-1], v2[i-2] + nums[i]);
        }
        
        return max(v1[n-1], v2[n-1]);
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        // rob nums[0..n-1].
        int mval[n];
        mval[0] = 0;
        mval[1] = nums[0];
        for (int i = 1, len = n - 1; i < len; ++ i) {
            mval[i+1] = max(mval[i], mval[i-1] + nums[i]);
        }
        
        // rob nums[1..n]. Be careful of indexing in for loop.
        int mval2[n];
        mval2[0] = 0;
        mval2[1] = nums[1];
        for (int i = 2; i < n; ++ i) {
            mval2[i] = max(mval2[i-1], mval2[i-2] + nums[i]);
        }
        
        return max(mval[n-1], mval2[n-1]);        
    }
};

/**
House Robber II
Difficulty: Medium

Note: This is an extension of House Robber.

After robbing those houses on that street, the thief has found himself 
a new place for his thievery so that he will not get too much attention. 
This time, all houses at this place are arranged in a circle. That means 
the first house is the neighbor of the last one. Meanwhile, the security 
system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money 
of each house, determine the maximum amount of money you can rob tonight 
without alerting the police.
 */
