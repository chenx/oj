class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0, n = nums.size();
        if (n < k) return 0;

        int i = 0;
        int avg = 0;
        for (; i < k; ++ i) {
            sum += nums[i];
        }
        avg = sum;

        for (; i < n; ++ i) {
            sum += nums[i] - nums[i-k];
            if (sum > avg) avg = sum;
        }

        return 1.0 * avg / k;
    }
};


/**
643. Maximum Average Subarray I
Easy

You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. 
Any answer with a calculation error less than 10-5 will be accepted.

 

Example 1:

Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75

Example 2:

Input: nums = [5], k = 1
Output: 5.00000
 */
