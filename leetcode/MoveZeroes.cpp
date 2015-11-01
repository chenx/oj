class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int L = 0; // last index of non-zero element.
        int len = nums.size();
        for (int i = 0; i < len; ++ i) {
            if (nums[i] != 0) {
                nums[L ++] = nums[i];
            }
        }
        for (; L < len; ++ L) {
            nums[L] = 0;
        }   
    }
};


/**
Move Zeroes
Difficulty: Easy

Given an array nums, write a function to move all 0's to the end of it 
while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, 
nums should be [1, 3, 12, 0, 0].

Note:

    You must do this in-place without making a copy of the array.
    Minimize the total number of operations.

 */
