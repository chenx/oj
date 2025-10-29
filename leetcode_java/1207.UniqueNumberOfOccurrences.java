class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        HashMap<Integer, Integer> map = new HashMap();
        for (int n : arr) map.put(n, map.getOrDefault(n, 0) + 1);

        HashSet<Integer> set = new HashSet();
        for (int value : map.values()) {
            if (set.contains(value)) return false;
            set.add(value);
        }
        return true;
    }
}

/**
1207. Unique Number of Occurrences
Easy

Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.
 */

