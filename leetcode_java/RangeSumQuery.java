public class NumArray {

    public NumArray(int[] nums) {
        int len = nums.length;
        if (len == 0) return;
        
        base = new int[len];
        sums = new int[len];
        
        int sum = 0;
        for (int i = 0; i < len; ++ i) {
            base[i] = nums[i];
            
            sum += nums[i];
            sums[i] = sum;
        }
    }

    public int sumRange(int i, int j) {
        return sums[j] - sums[i] + base[i];
    }
    
    private int[] base;
    private int[] sums;
}


// Your NumArray object will be instantiated and called as such:
// NumArray numArray = new NumArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);

/**
Range Sum Query - Immutable
Difficulty: Easy

Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:

Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3

Note:

    You may assume that the array does not change.
    There are many calls to sumRange function.
 */
