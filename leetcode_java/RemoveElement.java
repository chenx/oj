// This works. But does not keep original element order.
public class Solution {
    public int removeElement(int[] nums, int val) {
        int L = 0, R = nums.length - 1;
        
        while (L <= R) {
            if (nums[L] == val) {
                swap(nums, L, R);
                -- R;
            }
            else {
                ++ L;
            }
        }
        return L;
    }
    
    private void swap(int[] nums, int L, int R) {
        int tmp = nums[L];
        nums[L] = nums[R];
        nums[R] = tmp;
    }
}

// Same as Solution, just simplified code.
public class Solution2 {
    public int removeElement(int[] nums, int val) {
        int L = 0, R = nums.length - 1;
        
        while (L <= R) {
            if (nums[L] == val) swap(nums, L, R --);
            else ++ L;
        }
        return L;
    }
    
    private void swap(int[] nums, int L, int R) {
        int tmp = nums[L];
        nums[L] = nums[R];
        nums[R] = tmp;
    }
}

// This works too. Keeps original order of elements.
public class Solution3 {
    public int removeElement(int[] nums, int val) {
        int L = 0;
        
        for (int i = 0, len = nums.length; i < len; ++ i) {
            if (nums[i] != val) {
                if (L != i) nums[L] = nums[i];
                ++ L;
            }
        }
        return L;
    }
}

/**
Remove Element
Difficulty: Easy

Given an array and a value, remove all instances of that value in place 
and return the new length.

The order of elements can be changed. It doesn't matter what you leave 
beyond the new length. 
 */
