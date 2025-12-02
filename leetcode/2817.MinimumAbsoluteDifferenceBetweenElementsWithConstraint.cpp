// Simplified from Solution2.
class Solution3 {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int minDiff = INT_MAX;      
        multiset<int> elements;
      
        for (int i = x; i < nums.size(); ++ i) {
            elements.insert(nums[i - x]);
          
            // Find the smallest element >= nums[i] in the set
            auto iter = elements.lower_bound(nums[i]);
          
            if (iter != elements.end()) {
                minDiff = min(minDiff, *iter - nums[i]);
            }          
            if (iter != elements.begin()) {
                --iter;
                minDiff = min(minDiff, nums[i] - *iter);
            }
        }
      
        return minDiff;
    }
};


// From: https://algo.monster/liteproblems/2817
// Time: O(n log n)
class Solution2 {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        // Initialize the minimum difference with a large value (2^30)
        int minDiff = 1 << 30;
      
        // Use a multiset to maintain sorted elements that are at least x positions apart
        multiset<int> validElements;
      
        // Start from index x, ensuring we can look back at least x positions
        for (int i = x; i < nums.size(); ++i) {
            // Add the element that is exactly x positions behind current index
            // This ensures all elements in the set are at least x positions apart from nums[i]
            validElements.insert(nums[i - x]);
          
            // Find the smallest element >= nums[i] in the set
            auto lowerBoundIter = validElements.lower_bound(nums[i]);
          
            // If such an element exists, update minimum difference
            if (lowerBoundIter != validElements.end()) {
                minDiff = min(minDiff, *lowerBoundIter - nums[i]);
            }
          
            // Check the largest element < nums[i] (previous element in the set)
            if (lowerBoundIter != validElements.begin()) {
                --lowerBoundIter;
                minDiff = min(minDiff, nums[i] - *lowerBoundIter);
            }
        }
      
        return minDiff;
    }
};

// Times out for large input.
// Time: O(n^2)
class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int n = nums.size(), minDiff = INT_MAX;
        for (int i = 0; i < n - x; ++ i) {
            for (int j = i + x; j < n; ++ j) {
                minDiff = min(minDiff, abs(nums[i] - nums[j]));
            }
        }
        return minDiff;
    }
};


/**
2817. Minimum Absolute Difference Between Elements With Constraint
Medium

You are given a 0-indexed integer array nums and an integer x.

Find the minimum absolute difference between two elements in the array that are at least x indices apart.

In other words, find two indices i and j such that abs(i - j) >= x and abs(nums[i] - nums[j]) is minimized.

Return an integer denoting the minimum absolute difference between two elements that are at least x indices apart.

 

Example 1:

Input: nums = [4,3,2,4], x = 2
Output: 0
Explanation: We can select nums[0] = 4 and nums[3] = 4. 
They are at least 2 indices apart, and their absolute difference is the minimum, 0. 
It can be shown that 0 is the optimal answer.
 */
