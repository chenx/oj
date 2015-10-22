public class Solution {
    public void sortColors(int[] nums) {
        int L = 0, len = nums.length, p = 0, R = len - 1;
        while (p <= R) {
            if (nums[p] == 0) {
                if (p != L) swap(nums, p, L);
                ++ p;
                ++ L;
            }
            else if (nums[p] == 2) {
                swap(nums, p, R);
                -- R;
            }
            else {
                ++ p;
            }
        }
    }
    
    private void swap(int[] nums, int a, int b) {
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
    }
}

/**
Sort Colors
Difficulty: Medium

Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

click to show follow up.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
 */
