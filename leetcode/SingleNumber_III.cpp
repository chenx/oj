// This works. 
// Modified from: https://leetcode.com/discuss/67701/simple-solution-in-java
// There are many ways to solving this. 
// E.g., sort first, but that's O(nlogn). 
// Key is to find a property to separate the 2 numbers.
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0, len = nums.size();
        for (int i = 0; i < len; ++ i) {
            x ^= nums[i];
        }
        
        int mask = x & ~(x - 1); // or x & (~x + 1)
        vector<int> v(2, 0); // initialize to 0.
        
        for (int i = 0; i < len; ++ i) {
            // must put "()" around & statement.
            if ((nums[i] & mask) == 0) v[0] ^= nums[i]; 
            else v[1] ^= nums[i];
        }

        return v;        
    }
};

/**
Single Number III
Difficulty: Medium

Given an array of numbers nums, in which exactly two elements appear 
only once and all the other elements appear exactly twice. 
Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:

    The order of the result is not important. 
    So in the above example, [5, 3] is also correct.
    
    Your algorithm should run in linear runtime complexity. 
    Could you implement it using only constant space complexity?

 */
