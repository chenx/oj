class Solution {
    public boolean isAlienSorted(String[] words, String order) {
        HashMap<Character, Integer> pos = new HashMap<>();
        for (int i = 0; i < order.length(); ++ i) {
            pos.put(order.charAt(i), i);
        }

        int len = words.length;
        for (int i = 1; i < len; ++ i) {
            if(!lessThan(words[i-1], words[i], pos)) return false;
        }

        return true;
    }

    boolean lessThan(String a, String b, HashMap<Character, Integer> pos) {
        int len = Math.min(a.length(), b.length());
        boolean samePrefix = true;
        for (int i = 0; i < len; ++ i) {
            if (pos.get(a.charAt(i)) < pos.get(b.charAt(i))) return true;
            if (pos.get(a.charAt(i)) > pos.get(b.charAt(i))) return false;
        }
        return a.length() <= b.length();
    }
}

/**
953. Verifying An Alien Dictionary

In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different order. 
The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only 
if the given words are sorted lexicographically in this alien language.
 */
