// From: https://leetcode.com/problems/split-array-largest-sum/editorial/
// Binary Search.
// Here N is the length of the array and S is the sum of integers in the array.
// Time complexity: O(N⋅log(S))
// Space complexity: O(1)
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        // Find the sum of all elements and the maximum element
        int sum = 0;
        int maxElement = INT_MIN;
        for (int element : nums) {
            sum += element;
            maxElement = max(maxElement, element);
        }
        
        // Define the left and right boundary of binary search
        int left = maxElement;
        int right = sum;
        int minimumLargestSplitSum = 0;
        while (left <= right) {
            // Find the mid value
            int maxSumAllowed = left + (right - left) / 2;
            
            // Find the minimum splits. If splitsRequired is less than
            // or equal to k move towards left i.e., smaller values
            if (minimumSubarraysRequired(nums, maxSumAllowed) <= k) {
                right = maxSumAllowed - 1;
                minimumLargestSplitSum = maxSumAllowed;
            } else {
                // Move towards right if splitsRequired is more than k.
                left = maxSumAllowed + 1;
            }
        }
        
        return minimumLargestSplitSum;
    }

private:
    int minimumSubarraysRequired(vector<int>& nums, int maxSumAllowed) {
        int currentSum = 0;
        int splitsRequired = 0;
        
        for (int element : nums) {
            // Add element only if the sum doesn't exceed maxSumAllowed
            if (currentSum + element <= maxSumAllowed) {
                currentSum += element;
            } else {
                // If the element addition makes sum more than maxSumAllowed
                // Increment the splits required and reset sum
                currentSum = element;
                splitsRequired++;
            }
        }
        
        // Return the number of subarrays, which is the number of splits + 1
        return splitsRequired + 1;
    }
};


/**
410. Split Array Largest Sum
Hard

Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.

Example 2:

Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9. 
 */
