public class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int m = nums1.length, n = nums2.length, len = m + n;
        if ((len & 1) == 1) {
            return getKth(nums1, 0, m, nums2, 0, n, 1 + len/2);
        }
        else {
            return (getKth(nums1, 0, m, nums2, 0, n, len/2) +
                    getKth(nums1, 0, m, nums2, 0, n, 1 + len/2)) / 2.0;
        }
    }
    
    int getKth(int[] nums1, int offset1, int m, int[] nums2, int offset2, int n, int k) {
        if (m > n) return getKth(nums2, offset2, n, nums1, offset1, m, k);
        if (m == 0) return nums2[offset2 + k-1];
        if (k == 1) return Math.min(nums1[offset1], nums2[offset2]);
        
        int p1 = Math.min(k/2, m);
        int p2 = k - p1;
        
        if (nums1[offset1 + p1 - 1] < nums2[offset2 + p2 - 1]) {
            return getKth(nums1, offset1 + p1, m - p1, nums2, offset2, n, k - p1);
        }
        else {
            return getKth(nums1, offset1, m, nums2, offset2 + p2, n - p2, k - p2);
        }    
    }
}


/**
Median of Two Sorted Arrays
Difficulty: Hard

There are two sorted arrays nums1 and nums2 of size m and n respectively. 
Find the median of the two sorted arrays. The overall run time complexity 
should be O(log (m+n)).
 */
