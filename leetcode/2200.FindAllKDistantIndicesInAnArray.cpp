// Time: O(n)
// Space: O(n)
class Solution2 {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> indices;
        for (int i = 0, left = 0; i < nums.size(); ++ i) {
            if (nums[i] == key) {
                int start = max(left, i - k);
                int end = min(i + k, (int) nums.size() - 1);
                left = end + 1;
                for (int j = start; j <= end; ++ j) indices.push_back(j);
            }
        }
        return indices;
    }
};

// Time: O(n^2)
// Space: O(n)
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int> indices;
        for (int i = 0; i < nums.size(); ++ i) {
            if (nums[i] == key) {
                int start = max(0, i - k);
                int end = min(i + k, (int) nums.size() - 1);
                for (int j = start; j <= end; ++ j) indices.insert(j);
            }
        }
        return vector<int>(indices.begin(), indices.end());
    }
};


/**
2200. Find All K-Distant Indices in an Array
Easy

You are given a 0-indexed integer array nums and two integers key and k. A k-distant index is an index i 
of nums for which there exists at least one index j such that |i - j| <= k and nums[j] == key.

Return a list of all k-distant indices sorted in increasing order.

 

Example 1:

Input: nums = [3,4,9,1,3,9,5], key = 9, k = 1
Output: [1,2,3,4,5,6]
 */
