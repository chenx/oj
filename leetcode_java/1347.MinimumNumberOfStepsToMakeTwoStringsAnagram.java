class Solution {
    public int minSteps(String s, String t) {
        HashMap<Character, Integer> map = new HashMap<>();

        int n = s.length();
        for (int i = 0; i < n; ++ i) {
            char ch = s.charAt(i);
            map.put(ch, map.getOrDefault(ch, 0) - 1);
        }
        for (int i = 0; i < n; ++ i) {
            char ch = t.charAt(i);
            map.put(ch, map.getOrDefault(ch, 0) + 1);
        }

        int ans = 0;
        for (int val : map.values()) {
            ans += val > 0 ? val : 0;
        }
        // Methods below also work. 
        // for (char key : map.keySet()) {
        //     ans += (map.getOrDefault(key, 0) > 0) ? map.get(key) : 0;
        // }
        // for (Map.Entry<Character, Integer> entry : map.entrySet()) {
        //     ans += (entry.getValue() > 0) ? entry.getValue() : 0;
        // }
        return ans;
    }
}

/**
1347. Minimum Number of Steps to Make Two Strings Anagram
Medium

You are given two strings of the same length s and t. In one step you can choose any character of t and 
replace it with another character.

Return the minimum number of steps to make t an anagram of s.

An Anagram of a string is a string that contains the same characters with a different (or the same) ordering.
 */
