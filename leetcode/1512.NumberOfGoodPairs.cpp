// See: https://leetcode.com/problems/number-of-good-pairs/editorial/
// Time: O(n)
// Space: O(n)
class Solution2 {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int sum = 0;
        map<int, int> count; // <num, count>

        for (int num : nums) {
            sum += count[num];
            ++ count[num];
        }
        return sum;
    }
};


// Time: O(n^2)
// Space: O(1)
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count = 0, n = nums.size();
        for (int i = 0; i < n - 1; ++ i) {
            for (int j = i + 1; j < n; ++ j) {
                if (nums[i] == nums[j]) ++ count;
            }
        }
        return count;
    }
};


/**
1512. Number of Good Pairs
Easy

Given an array of integers nums, return the number of good pairs.

A pair (i, j) is called good if nums[i] == nums[j] and i < j.

 

Example 1:

Input: nums = [1,2,3,1,1,3]
Output: 4
Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.

Example 2:

Input: nums = [1,1,1,1]
Output: 6
Explanation: Each pair in the array are good.

Example 3:

Input: nums = [1,2,3]
Output: 0
 */
