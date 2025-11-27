// See: https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/editorial/
// 2 sortings.
// Time: O(nlogn)
// Space: O(n)
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();

        vector<vector<int>> v;
        for (int i = 0; i < n; ++ i) {
            v.push_back({i, nums[i]});
        }
        sort(v.begin(), v.end(), comp); // sort in reverse order of nums[i].

        sort(v.begin(), v.begin() + k); // sort first k by index i.

        vector<int> result;
        for (int i = 0; i < k; ++ i) {
            result.push_back(nums[v[i][0]]);
        }
        return result;
    }

    static bool comp(vector<int>& a, vector<int>& b) {
        return a[1] > b[1];
    }
};

// If don't need to keep the relative order of elements.
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return vector<int>(nums.begin() + nums.size() - k, nums.end());
    }
};

/**
2099. Find Subsequence of Length K With the Largest Sum
Easy

You are given an integer array nums and an integer k. You want to find a subsequence of nums of length k 
that has the largest sum.

Return any such subsequence as an integer array of length k.

A subsequence is an array that can be derived from another array by deleting some or no elements without 
changing the order of the remaining elements.

 

Example 1:

Input: nums = [2,1,3,3], k = 2
Output: [3,3]
Explanation:
The subsequence has the largest sum of 3 + 3 = 6.

Example 2:

Input: nums = [-1,-2,3,4], k = 3
Output: [-1,3,4]
Explanation: 
The subsequence has the largest sum of -1 + 3 + 4 = 6.
 */
