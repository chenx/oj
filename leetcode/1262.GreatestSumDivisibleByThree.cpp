// Same as Solution.
class Solution2 {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> f = {0, INT_MIN, INT_MIN};
        for (int num : nums) {
            vector<int> g = f;
            for (int i = 0; i < 3; ++i) {
                int k = (i + num % 3) % 3; // This also works: int k = (i + num) % 3;
                g[k] = max(g[k], f[i] + num);
            }
            f = g;
        }
        return f[0];
    }
};

// From: https://leetcode.com/problems/greatest-sum-divisible-by-three/editorial/
// DP
// Let f(i,j) be the maximum sum achievable using the first i elements such that the sum modulo 3 equals j.
// f(i,j)=max{f(i−1,j),f(i−1,(j−nums[i])mod3)+nums[i]}
// Time complexity: O(n).
// Space complexity: O(1).
//
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> f = {0, INT_MIN, INT_MIN};
        for (int num : nums) {
            vector<int> g = f;
            for (int i = 0; i < 3; ++i) {
                g[(i + num % 3) % 3] = max(g[(i + num % 3) % 3], f[i] + num);
            }
            f = move(g);
        }
        return f[0];
    }
};


/**
1262. Greatest Sum Divisible by Three
Medium

Given an integer array nums, return the maximum possible sum of elements of the array such that it is divisible by three.

 

Example 1:

Input: nums = [3,6,5,1,8]
Output: 18
Explanation: Pick numbers 3, 6, 1 and 8 their sum is 18 (maximum sum divisible by 3).

Example 2:

Input: nums = [4]
Output: 0
Explanation: Since 4 is not divisible by 3, do not pick any number.

Example 3:

Input: nums = [1,2,3,4,4]
Output: 12
Explanation: Pick numbers 1, 3, 4 and 4 their sum is 12 (maximum sum divisible by 3).
 */
