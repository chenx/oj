// DP
// See Python solution: https://blog.csdn.net/codename_cys/article/details/154679776

// Works. But time out for large input.
// Time: O(N^2)
class Solution2 {
public:
    int longestSubarray(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        // Return longest non-drecreasing array after removing 1 element each time.
        int n = nums.size(), maxLen = 0;
        for (int i = 0; i < n; ++ i) {
            maxLen = max(maxLen, getMaxNonDecreasingLen(nums, i));
        }
        return maxLen + 1;
    }

    int getMaxNonDecreasingLen(vector<int>& nums, int indexToIgnore) {
        int n = nums.size();
        if (n == 0) return 0;

        int maxLen = 1, len = 1;
        for (int i = 1; i < n; ++ i) {
            if (indexToIgnore == i) continue;

            int diff = nums[i] - nums[i-1];
            if (i - 1 == indexToIgnore) {
                if (i == 1) continue;
                diff = nums[i] - nums[i-2];
            }

            if (diff >= 0) {
                ++ len;
                // maxLen = max(maxLen, len);
            } else {
                maxLen = max(maxLen, len);
                len = 1;
            }
        }
        maxLen = max(maxLen, len);
        return maxLen;
    }
};


// Works. But OOM for large input.
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // Return longest non-drecreasing array after removing 1 element each time.
        int n = nums.size(), maxLen = 0;
        for (int i = 0; i < n; ++ i) {
            auto arr = nums;
            arr.erase(arr.begin() + i);
            maxLen = max(maxLen, getMaxNonDecreasingLen(arr));
        }
        return maxLen + 1;
    }

    int getMaxNonDecreasingLen(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int maxLen = 1, len = 1;
        for (int i = 1; i < n; ++ i) {
            if (nums[i] >= nums[i-1]) {
                ++ len;
                maxLen = max(maxLen, len);
            } else {
                len = 1;
            }
        }
        return maxLen;
    }
};


/**
3738. Longest Non-Decreasing Subarray After Replacing at Most One Element
Medium

You are given an integer array nums.

You are allowed to replace at most one element in the array with any other integer value of your choice.

Return the length of the longest non-decreasing

that can be obtained after performing at most one replacement.

An array is said to be non-decreasing if each element is greater than or equal to its previous one (if it exists).

 

Example 1:

Input: nums = [1,2,3,1,2]

Output: 4

Explanation:

Replacing nums[3] = 1 with 3 gives the array [1, 2, 3, 3, 2].

The longest non-decreasing subarray is [1, 2, 3, 3], which has a length of 4.

Example 2:

Input: nums = [2,2,2,2,2]

Output: 5

Explanation:

All elements in nums are equal, so it is already non-decreasing and the entire nums forms a subarray of length 5.
 */
