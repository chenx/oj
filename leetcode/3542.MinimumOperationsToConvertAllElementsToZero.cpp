// From: https://leetcode.com/problems/minimum-operations-to-convert-all-elements-to-zero/editorial/
// Time complexity: O(n). n is the length of the array.
// Space complexity: O(n).
class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> s;
        int res = 0;
        for (int a : nums) {
            while (!s.empty() && s.back() > a) {
                s.pop_back();
            }
            if (a == 0) continue;
            if (s.empty() || s.back() < a) {
                ++res;
                s.push_back(a);
            }
        }
        return res;
    }
};


/**
3542. Minimum Operations to Convert All Elements to Zero
Medium

You are given an array nums of size n, consisting of non-negative integers. Your task is to apply some (possibly zero) 
operations on the array so that all elements become 0.

In one operation, you can select a

[i, j] (where 0 <= i <= j < n) and set all occurrences of the minimum non-negative integer in that subarray to 0.

Return the minimum number of operations required to make all elements in the array 0.

 

Example 1:

Input: nums = [0,2]

Output: 1

Explanation:

    Select the subarray [1,1] (which is [2]), where the minimum non-negative integer is 2. Setting 
        all occurrences of 2 to 0 results in [0,0].
    Thus, the minimum number of operations required is 1.
 */
