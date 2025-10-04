class Solution {
    // Array are sorted.
    public int[] intersect(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        
        List<Integer> ans = new ArrayList<>();
        for (int i = 0, j = 0; i < nums1.length && j < nums2.length; ) {
            if (nums1[i] < nums2[j]) ++ i;
            else if (nums1[i] > nums2[j]) ++ j;
            else {
                ans.add(nums1[i]);
                ++i;
                ++j;
            }
        }
        
        int[] res = new int[ans.size()];
        for (int i = 0; i < ans.size(); ++ i) {
            res[i] = ans.get(i);
        }
        return res;
    }

    // Array are NOT sorted.
    public int[] intersect2(int[] nums1, int[] nums2) {
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
