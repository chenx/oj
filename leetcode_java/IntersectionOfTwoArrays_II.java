class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        HashMap<Integer, Integer> h = new HashMap<>();
        for (int n : nums1) {
            int count = h.get(n) != null ? h.get(n) : 0;
            h.put(n, count + 1);
        }
        
        List<Integer> ans = new ArrayList<Integer>();
        for (int n : nums2) {
            if (h.get(n) != null && h.get(n) > 0) {
                ans.add(n);
                h.put(n, h.get(n) - 1);
            }
        }
        
        return ans.stream().mapToInt(Integer::intValue).toArray();        
    }
}

/**
Intersection of Two Arrays II

Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result 
must appear as many times as it shows in both arrays and you may return the result in any order.
 */
