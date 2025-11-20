// From: https://leetcode.com/problems/keep-multiplying-found-values-by-two/editorial/
// Time complexity: O(n).
// Space complexity: O(n).
class Solution2 {
public:
    int findFinalValue(vector<int>& nums, int original) {
        set<int> set(nums.begin(), nums.end());
        while (set.contains(original)) {
            original *= 2;
        }
        return original;
    }
};

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());
        while (findValue(nums, original)) {
            original *= 2;
        }
        return original;
    }

    bool findValue(vector<int>& nums, int original) {
        int L = 0, R = nums.size() - 1;
        while (L <= R) {
            int M = L + (R-L)/2;
            int val = nums[M];
            if (val == original) return true;
            else if (val < original) L = M+1;
            else R = M-1;
        }
        return false;
    }
};

/**
2154. Keep Multiplying Found Values by Two
Easy

You are given an array of integers nums. You are also given an integer original which is the 
first number that needs to be searched for in nums.

You then do the following steps:

    If original is found in nums, multiply it by two (i.e., set original = 2 * original).
    Otherwise, stop the process.
    Repeat this process with the new number as long as you keep finding the number.

Return the final value of original.
 */
