public class Solution {
    // This works. Uses O(2n) extra space, for L[] and R[]. 
    public int[] productExceptSelf(int[] nums) {
        int len = nums.length;
        if (len <= 1) return nums;

        int[] L = new int[len];
        L[0] = nums[0];
        for (int i = 1; i < len; ++ i) L[i] = L[i-1] * nums[i];
        
        int[] R = new int[len];
        R[len - 1] = nums[len - 1];
        for (int i = len - 2; i >= 0; -- i) R[i] = R[i+1] * nums[i];
        
        int[] ans = new int[len];
        ans[0] = R[1];
        for (int i = 1; i < len - 1; ++ i) ans[i] = L[i-1] * R[i+1];
        ans[len - 1] = L[len - 2];
        
        return ans;
    }
    
    // This works too. Uses constant space.
    public int[] productExceptSelf2(int[] nums) {
        int len = nums.length;
        if (len <= 1) return nums;
        
        int[] ans = new int[len];
        ans[0] = nums[0];
        for (int i = 1; i < len; ++ i) {
            ans[i] = ans[i-1] * nums[i];
        }
        
        for (int i = len - 2; i >= 0; -- i) {
            nums[i] *= nums[i+1];
        }
        
        ans[len - 1] = ans[len - 2];
        for (int i = len - 2; i >= 1; -- i) {
            ans[i] = ans[i-1] * nums[i+1];
        }
        ans[0] = nums[1];
        
        return ans;
    }
}


/**
Product of Array Except Self
Difficulty: Medium

Given an array of n integers where n > 1, nums, return an array output 
such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array 
does not count as extra space for the purpose of space complexity analysis.)
 */
