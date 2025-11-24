// From: https://leetcode.com/problems/combination-sum-iv/editorial/
// Let T be the target value, and N be the number of elements in the input array.
// Time Complexity: O(T⋅N)
// Space Complexity: O(T)
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // minor optimization
        // Arrays.sort(nums);
        vector<unsigned long long> dp(target + 1, 0);
        dp[0] = 1;

        for (int combSum = 1; combSum <= target; ++ combSum) {
            for (int num : nums) {
                if (combSum - num >= 0)
                    dp[combSum] += dp[combSum - num];
                // minor optimizaton, early stopping
                // else
                //     break;
            }
        }
        return dp[target];
    }
};


/**
377. Combination Sum IV
Medium

Given an array of distinct integers nums and a target integer target, return the number of 
possible combinations that add up to target.

The test cases are generated so that the answer can fit in a 32-bit integer.

 

Example 1:

Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.

Example 2:

Input: nums = [9], target = 3
Output: 0
 */
