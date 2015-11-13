// This works. 
// Modified from: https://leetcode.com/discuss/67701/simple-solution-in-java
// There are many ways to solving this. 
// E.g., sort first, but that's O(nlogn). 
// Key is to find a property to separate the 2 numbers.
public class Solution {
    public int[] singleNumber(int[] nums) {
        int x = 0, len = nums.length;
        
        for (int i = 0; i < len; ++ i) {
            x ^= nums[i];
        }
        // now x is XOR of the 2 single numbers.
        // now get the lowest bit where the 2 numbers diff.
        int mask = x & (~x + 1); // or x & ~(x-1)
        
        int n1 = 0, n2 = 0;
        for (int i = 0; i < len; ++ i) {
            if ((mask & nums[i]) == 0) n1 ^= nums[i];
            else n2 ^= nums[i];
        }
        
        int[] arr = new int[]{n1, n2};
        return arr;
    }
}

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
