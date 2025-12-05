// Sort, and pair (0, 1), (2, 3), ...
// Time: O(n*log(n))
// Space: O(1)
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int sum = 0;
        for (int i = 0; i < nums.size(); i += 2) {
            sum += nums[i];
        }
        return sum;
    }
};


// From: https://leetcode.com/problems/array-partition/editorial/
// Counting sort. 
// This is hard to understand, and also may not be faster in reality.
class Solution {
public:
    const static int K = 10000;
        
    int arrayPairSum(vector<int>& nums) {
        // Store the frequency of each element
        int elementToCount[2 * K + 1] = {0};
        for (int element : nums) {
            // Add K to element to offset negative values
            elementToCount[element + K]++;
        }
        
        // Initialize sum to zero
        int maxSum = 0;
        bool isEvenIndex = true;
        for (int element = 0; element <= 2 * K; element++) {
            while (elementToCount[element]) {
                // Add element if it is at even position
                maxSum += (isEvenIndex ? element - K : 0);
                // Flip the value (one to zero or zero to one)
                isEvenIndex = !isEvenIndex;
                // Decrement the frequency count
                elementToCount[element]--;
            }
        }
        return maxSum;
    }
};


/**
561. Array Partition
Easy

Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2), ..., (an, bn) 
such that the sum of min(ai, bi) for all i is maximized. Return the maximized sum.

 

Example 1:

Input: nums = [1,4,3,2]
Output: 4
Explanation: All possible pairings (ignoring the ordering of elements) are:
1. (1, 4), (2, 3) -> min(1, 4) + min(2, 3) = 1 + 2 = 3
2. (1, 3), (2, 4) -> min(1, 3) + min(2, 4) = 1 + 2 = 3
3. (1, 2), (3, 4) -> min(1, 2) + min(3, 4) = 1 + 3 = 4
So the maximum possible sum is 4.
 */
