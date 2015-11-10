public class Solution {
    public void nextPermutation(int[] nums) { // e.g. 14322 -> 24321 -> 21234
        int n = nums.length, i, j;
        
        for (i = n - 2; i >= 0 && nums[i] >= nums[i+1]; -- i) {}
        if (i < 0) {
            reverse(nums, 0, n-1);
            return;
        }
        // now nums[i] < nums[i+1]
        
        for (j = n - 1; nums[j] <= nums[i]; -- j) {}
        // nums[j] is the first that > nums[i].
        swap(nums, i, j);
        
        reverse(nums, i+1, n-1);
    }
    
    private void swap(int[] A, int L, int R) {
        int tmp = A[L];
        A[L] = A[R];
        A[R] = tmp;
    }
    
    private void reverse(int[] A, int L, int R) {
        while (L < R) {
            int tmp = A[L];
            A[L] = A[R];
            A[R] = tmp;
            ++ L; -- R;
        }
    }
}

/**
Next Permutation
Difficulty: Medium

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
 */
