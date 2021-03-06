public class Solution {
    public void rotate(int[] nums, int k) {
        int len = nums.length;
        k %= len;
        if (k == 0) return;

        k = len - 1 - k; // note this.
        reverse(nums, 0, k);
        reverse(nums, k+1, len-1);
        reverse(nums, 0, len-1);
    }
    
    void reverse(int[] v, int start, int end) {
        for (; start < end; ++ start, -- end) {
            int tmp = v[start];
            v[start] = v[end];
            v[end] = tmp;
        }        
    }
}

// This works too.
public class Solution2 {
    public void rotate(int[] nums, int k) {
        int len = nums.length;
        k %= len; // this is needed!
        reverse(nums, 0, len - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, len - 1);
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
Rotate Array.

Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

[show hint]
Hint:
Could you do it in-place with O(1) extra space?

Related problem: Reverse Words in a String II
 */
