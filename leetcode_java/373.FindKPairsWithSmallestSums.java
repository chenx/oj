class Solution {
    public List<List<Integer>> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        List<List<Integer>> ans = new ArrayList<>();

        Queue<Pair<Integer, Pair<Integer, Integer>>> minHeap = 
            new PriorityQueue<>((a, b) -> a.getKey() - b.getKey());

        HashSet<Pair<Integer, Integer>> visited = new HashSet<>();
        visited.add(new Pair(0, 0));

        minHeap.add(new Pair(nums1[0] + nums2[0], new Pair(0, 0)));
        while (! minHeap.isEmpty() && ans.size() < k) {  // NOTE: ans.size() < k
            int sum = minHeap.peek().getKey();
            int i = minHeap.peek().getValue().getKey();
            int j = minHeap.peek().getValue().getValue();
            minHeap.remove();

            // List<Integer> item = new ArrayList();
            // item.add(nums1[i]); item.add(nums2[j]);
            // ans.add(item);
            ans.add(new ArrayList(Arrays.asList(nums1[i], nums2[j])));

            if (i + 1 < nums1.length && !visited.contains(new Pair(i+1, j))) {
                minHeap.add(new Pair(nums1[i+1] + nums2[j], new Pair(i+1, j)));
                visited.add(new Pair(i+1, j));
            }
            if (j + 1 < nums2.length && !visited.contains(new Pair(i, j+1))) {
                minHeap.add(new Pair(nums1[i] + nums2[j+1], new Pair(i, j+1)));
                visited.add(new Pair(i, j+1));
            }
        }

        return ans;
    }
}
