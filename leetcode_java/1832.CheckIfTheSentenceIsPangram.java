class Solution {
    public boolean checkIfPangram(String sentence) {
        HashMap<Character, Integer> map = new HashMap<>();

        int count = 0;
        for (int i = 0; i < sentence.length(); ++ i) {
            char ch = sentence.charAt(i);
            map.put(ch, 1 + map.getOrDefault(ch, 0));
            if (map.get(ch) == 1) ++ count;
        }
        return count == 26;
    }
}

/**
1832. Check if the Sentence Is Pangram

A pangram is a sentence where every letter of the English alphabet appears at least once.

Given a string sentence containing only lowercase English letters, return true if sentence 
is a pangram, or false otherwise.
 */
