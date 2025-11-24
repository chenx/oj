class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++ i) {
            int sum = 0, num = nums[i];
            while (num > 0) {
                sum += (num % 10);
                num /= 10;
            }
            if (sum == i) return i;
        }
        return -1;
    }
};


/**
3550. Smallest Index With Digit Sum Equal to Index
Easy

You are given an integer array nums.

Return the smallest index i such that the sum of the digits of nums[i] is equal to i.

If no such index exists, return -1.
 */
