public class Solution {
    public int findKthLargest(int[] nums, int k) {
        int len = nums.length;
        findKth(nums, 0, len - 1, len - k); // convert from k-th largest to k-th smallest.
        return nums[len - k];
    }
    
    // This gets the kth smallest.
    private void findKth(int[] nums, int left, int right, int k) {
        if (left >= right) return;
        
        swap(nums, left, left + (right - left) / 2);
        int pivot = nums[left];
        int L = left + 1, R = right;
        
        while (L <= R) {
            while (L <= R && nums[L] < pivot) ++ L;
            while (L <= R && nums[R] > pivot) -- R;
            if (L < R) {
                swap(nums, L, R);
                ++ L; -- R;
            }
            else {
                ++ L;
            }
        }
        swap(nums, left, R);
        
        if (R < k) findKth(nums, R+1, right, k);
        if (R > k) findKth(nums, left, R-1, k);
    }
    
    private void swap(int[] nums, int L, int R) {
        int tmp = nums[L];
        nums[L] = nums[R];
        nums[R] = tmp;
    }
}


/**
Kth Largest Element in an Array
Difficulty: Medium

Find the kth largest element in an unsorted array. Note that it is the 
kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
 */
