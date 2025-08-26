// Works too. O(1) space!
class Solution4 {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        long long a = 0, b = nums[0];
        for (int i = 2; i <= n; ++ i) {
            int tmp = max(b, a + nums[i-1]);
            a = b;
            b = tmp;
        }
        
        return b;
    }
};

// Works too.
class Solution3 {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        vector<int> v(n+1, 0);
        v[0] = 0;
        v[1] = nums[0];
        for (int i = 2; i <= n; ++ i) {
            v[i] = max(v[i-1], nums[i-1] + v[i-2]);
        }
        
        return v[n];
    }
};

// Works.
class Solution2 {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector<int> maxVal(n);
        maxVal[0] = nums[0];
        maxVal[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; ++ i) {
            maxVal[i] = max(maxVal[i-1], nums[i] + maxVal[i-2]);
        }
        return maxVal[n-1];
    }
};

// This works. Uses DP.
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        vector<int> maxv(n + 1);
        maxv[0] = 0;
        maxv[1] = nums[0];
        
        for (int i = 1; i < n; ++ i) {
            maxv[i+1] = max(maxv[i], maxv[i-1] + nums[i]);
        }
        
        return maxv[n];
    }
};

/*
House Robber

You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, the only constraint 
stopping you from robbing each of them is that adjacent houses have 
security system connected and it will automatically contact the police 
if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money 
of each house, determine the maximum amount of money you can rob tonight 
without alerting the police.
 */
