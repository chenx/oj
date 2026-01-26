class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        def getKth(nums1, offset1, nums2, offset2, k):
            m = len(nums1) - offset1
            n = len(nums2) - offset2

            if m > n:
                return getKth(nums2, offset2, nums1, offset1, k)
            if m == 0:
                return nums2[offset2 + k - 1]
            if k == 1:
                return min(nums1[offset1 + k - 1], nums2[offset2 + k - 1])
            
            pa = min(k//2, m)
            pb = k - pa

            if nums1[offset1 + pa - 1] < nums2[offset2 + pb - 1]:
                return getKth(nums1, offset1 + pa, nums2, offset2, k - pa)
            else:
                return getKth(nums1, offset1, nums2, offset2 + pb, k - pb)

        n1, n2 = len(nums1), len(nums2)
        total = n1 + n2

        if (total & 1):
            return getKth(nums1, 0, nums2, 0, 1 + total//2)
        else:
            return (getKth(nums1, 0, nums2, 0, total//2) + getKth(nums1, 0, nums2, 0, 1 + total//2)) / 2.0


/**
4. Median of Two Sorted Arrays
Hard

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).
 */
