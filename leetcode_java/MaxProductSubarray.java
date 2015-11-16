public class Solution {
    public int maxProduct(int[] nums) {
        int len = nums.length;
        if (len == 0) return 0;
        
        int p = nums[0], mp = p;
        for (int i = 1; i < len; ++ i) {
            if (p == 0) p = 1;
            p *= nums[i];
            mp = Math.max(mp, p);
        }
        
        p = nums[len - 1];
        mp = Math.max(mp, p);
        for (int i = len - 2; i >= 0; -- i) {
            if (p == 0) p = 1;
            p *= nums[i];
            mp = Math.max(mp, p);
        }
        
        return mp;
    }
}

/**
Maximum Product Subarray
Difficulty: Medium

Find the contiguous subarray within an array (containing at least one number) 
which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6. 
 */
