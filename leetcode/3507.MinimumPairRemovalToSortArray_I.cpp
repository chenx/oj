class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int steps = 0;
        vector<int> minSumPair(2);

        while (! isIncremental(nums)) {
            int minSum = INT_MAX;
            for (int i = 1; i < nums.size(); ++ i) {
                int sum = nums[i-1] + nums[i];
                if (sum < minSum) {
                    minSum = sum;
                    minSumPair = {i-1, i};
                }
            }

            nums.erase(nums.begin() + minSumPair[1]);
            // nums.erase(nums.begin() + minSumPair[0]); // this works too, since the nums array will shift left.
            nums.erase(nums.begin() + minSumPair[0]);
            nums.insert(nums.begin() + minSumPair[0], minSum);

            ++ steps;
        }
        return steps;
    }

    bool isIncremental(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++ i) {
            if (nums[i-1] > nums[i]) return false;
        }
        return true;
    }
};


/**
3507. Minimum Pair Removal to Sort Array I
Easy

Given an array nums, you can perform the following operation any number of times:

    Select the adjacent pair with the minimum sum in nums. If multiple such pairs exist, choose the leftmost one.
    Replace the pair with their sum.

Return the minimum number of operations needed to make the array non-decreasing.

An array is said to be non-decreasing if each element is greater than or equal to its previous element (if it exists).

 

Example 1:

Input: nums = [5,2,3,1]

Output: 2

Explanation:

    The pair (3,1) has the minimum sum of 4. After replacement, nums = [5,2,4].
    The pair (2,4) has the minimum sum of 6. After replacement, nums = [5,6].

The array nums became non-decreasing in two operations.

Example 2:

Input: nums = [1,2,2]

Output: 0

Explanation:

The array nums is already sorted.
 */
