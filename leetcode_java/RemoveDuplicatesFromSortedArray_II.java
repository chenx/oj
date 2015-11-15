public class Solution {
    public int removeDuplicates(int[] nums) {
        int len = nums.length;
        if (len <= 1) return len;
        
        int v = nums[0], L = 1, ct = 1;
        for (int i = 1; i < len; ++ i) {
            if (v == nums[i]) {
                if (ct == 1) {
                    nums[L] = nums[i];
                    ++ L;
                    ++ ct; 
                }
            }
            else {
                v = nums[L] = nums[i];
                ++ L;
                ct = 1;
            }
        }
        
        return L;
    }
}

/**
Remove Duplicates from Sorted Array II
Difficulty: Medium

Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements 
of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave 
beyond the new length.
 */
