// Works. O(n) time, O(1) space.
class Solution2 {
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


// O(n) time, O(n) space.
class Solution {
public:
    /**
     * @param A: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> A) {
        int n = A.size();
        if (n == 0) return 0;
        
        vector<long long> DP(n+1, 0);
        
        DP[0] = 0;
        DP[1] = A[0];
        
        for (int i = 2; i <= n; ++ i) {
            DP[i] = max(DP[i-1], DP[i-2] + A[i-1]);
        }
        
        return DP[n];
    }
};


/**
House Robber

You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, the only constraint 
stopping you from robbing each of them is that adjacent houses have 
security system connected and it will automatically contact the police 
if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money 
of each house, determine the maximum amount of money you can rob tonight 
without alerting the police.

Example

Given [3, 8, 4], return 8.
Challenge

O(n) time and O(1) memory.

 */
