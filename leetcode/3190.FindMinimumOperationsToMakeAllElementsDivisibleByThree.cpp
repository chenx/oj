// A number: 3k, 3k+1, 3k+2. Only one operation is needed to make it divisible by 3.
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            if (num % 3 != 0) ++ result;
        }
        return result;
    }
};


/**
3190. Find Minimum Operations to Make All Elements Divisible by Three
Easy

You are given an integer array nums. In one operation, you can add or subtract 1 from any element of nums.

Return the minimum number of operations to make all elements of nums divisible by 3.

 

Example 1:

Input: nums = [1,2,3,4]

Output: 3

Explanation:

All array elements can be made divisible by 3 using 3 operations:

    Subtract 1 from 1.
    Add 1 to 2.
    Subtract 1 from 4.
 */
