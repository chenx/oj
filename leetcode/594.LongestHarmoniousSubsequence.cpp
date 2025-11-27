// See: https://leetcode.com/problems/longest-harmonious-subsequence/editorial/
class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> count; // <num, frequency>
        for (int num : nums) ++ count[num];

        int result = 0;
        for (auto [num, frequency] : count) {
            if (count.contains(num + 1)) {
                result = max(result, count[num] + count[num+1]);
            }
        }
        return result;
    }
};


/**
594. Longest Harmonious Subsequence
Easy

We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.

Given an integer array nums, return the length of its longest harmonious

among all its possible subsequences.

 

Example 1:

Input: nums = [1,3,2,2,5,2,3,7]

Output: 5

Explanation:

The longest harmonious subsequence is [3,2,2,2,3].

Example 2:

Input: nums = [1,2,3,4]

Output: 2

Explanation:

The longest harmonious subsequences are [1,2], [2,3], and [3,4], all of which have a length of 2.

Example 3:

Input: nums = [1,1,1,1]

Output: 0

Explanation:

No harmonic subsequence exists.
 */
