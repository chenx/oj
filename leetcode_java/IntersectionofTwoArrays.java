class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        HashSet<Integer> h = new HashSet<>();
        for (int n : nums1) h.add(n);
        
        HashSet<Integer> h2 = new HashSet<>();
        for (int n : nums2) {
            if (h.contains(n)) h2.add(n);
        }

        return h2.stream().mapToInt(Integer::intValue).toArray();
    }
}

/**
Intersection of Two Arrays

Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result 
must be unique and you may return the result in any order.
 */
