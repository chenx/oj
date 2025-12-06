// Time: O(n) + O(log(min(minval, maxval)))
// Space: O(1)
class Solution {
public:
    int findGCD(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int minval = nums[0], maxval = nums[0];
        for (int i = 1; i < nums.size(); ++ i) {
            minval = min(minval, nums[i]);
            maxval = max(maxval, nums[i]);
        }

        // can use std::gcd() too.
        return gcd(minval, maxval);
    }

    // https://en.wikipedia.org/wiki/Euclidean_algorithm
    int gcd(int a, int b) {
        while (b != 0) {
            int tmp = b;
            b = a % b;
            a = tmp;
        }
        return a;
    }
};


/**
1979. Find Greatest Common Divisor of Array
Easy

Given an integer array nums, return the greatest common divisor of the smallest number and largest number in nums.

The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.

 

Example 1:

Input: nums = [2,5,6,9,10]
Output: 2
 */
