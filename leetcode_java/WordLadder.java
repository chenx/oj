// This works. 
// Optimized from Solution, and passes all tests.
// Note the use of toCharArray(), and let j be char type to avoid cast.
public class Solution2 {
    public int ladderLength(String beginWord, String endWord, Set<String> wordList) {
        if (beginWord.equals(endWord)) return 1;
        Queue<String> q = new LinkedList<String>(); // <string, distance>
        HashMap<String, Integer> used = new HashMap<String, Integer>();
        int dist = 0;
        
        q.add(beginWord);
        used.put(beginWord, 1);
        
        while (! q.isEmpty()) {
            String s = q.peek();
            char[] sa = s.toCharArray(); // <--
            int d = used.get(s); 
            q.remove();
            
            for (int i = 0, len = s.length(); i < len; ++ i) {
                char c = sa[i];
                for (char j = 'a'; j < 'z'; ++ j) { // <--
                    if (c == j) continue;

                    sa[i] = j;
                    String t = String.valueOf(sa); // <--

                    if (t.equals(endWord)) {
                        if (dist == 0 || dist > 1 + d) dist = 1 + d;
                        //return dist; // this works too, but use the above for safe.
                    }
                    else {
                        if (wordList.contains(t) && ! used.containsKey(t)) {
                            q.add(t);
                            used.put(t, 1 + d);
                        }
                    }
                } // end of for 
                sa[i] = c;
            } // end of for
        } // end of while
        
        return dist;
    }
}

// This should work. But time out for large test.
public class Solution {
    public int ladderLength(String beginWord, String endWord, Set<String> wordList) {
        if (beginWord.equals(endWord)) return 1;
        Queue<String> q = new LinkedList<String>(); // <string, distance>
        HashMap<String, Integer> used = new HashMap<String, Integer>();
        int dist = 0;
        
        q.add(beginWord);
        used.put(beginWord, 1);
        
        while (! q.isEmpty()) {
            String s = q.peek();
            int d = used.get(s); 
            q.remove();
            
            for (int i = 0, len = s.length(); i < len; ++ i) {
                char c = s.charAt(i);
                for (int j = 0; j < 26; ++ j) {
                    if (c == (char) ('a' + j)) continue;

                    //s.setCharAt(i, (char) ('a' + j));
                    s = s.substring(0, i) + ( (char) ('a' + j) ) + s.substring(i + 1);

                    if (s.equals(endWord)) {
                        if (dist == 0 || dist > 1 + d) {
                            dist = 1 + d;
                            return dist;
                        }
                    }
                    else {
                        if (wordList.contains(s) && ! used.containsKey(s)) {
                            q.add(s);
                            used.put(s, 1 + d);
                        }
                    }
                } // end of for 
                //s.setCharAt(i, c); // recover s[i].
                s = s.substring(0, i) + c + s.substring(i + 1);
            } // end of for
        } // end of while
        
        return dist;        
    }
}


/**
Word Ladder
Difficulty: Medium

Given two words (beginWord and endWord), and a dictionary's word list, 
find the length of shortest transformation sequence from beginWord to 
endWord, such that:

    Only one letter can be changed at a time
    Each intermediate word must exist in the word list

For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:

    Return 0 if there is no such transformation sequence.
    All words have the same length.
    All words contain only lowercase alphabetic characters.

 */
