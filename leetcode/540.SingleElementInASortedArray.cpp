class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = 0;
        for (int num : nums) n ^= num;
        return n;
    }
};

/**
540. Single Element in a Sorted Array

You are given a sorted array consisting of only integers where every element appears exactly twice, 
except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.
 */
