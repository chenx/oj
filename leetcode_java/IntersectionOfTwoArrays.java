class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        HashSet<Integer> set = new HashSet<>();
        for (int i : nums1) {
            set.add(i);
        }

        HashSet<Integer> intersection = new HashSet<>();
        for (int i : nums2) {
            if (set.contains(i)) intersection.add(i);
        }

        int[] ret = new int[intersection.size()];
        int count = 0;
        for (int i : intersection) {
            ret[count ++] = i;
        }

        return ret;
    }
}

/**
349. Intersection of Two Arrays

Given two integer arrays nums1 and nums2, return an array of their . Each element in the result must be unique 
and you may return the result in any order.
 */
