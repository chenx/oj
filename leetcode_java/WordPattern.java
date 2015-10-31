public class Solution {
    public boolean wordPattern(String pattern, String str) {
        Map<Character, Integer> m1 = new HashMap<Character, Integer>();
        Map<String, Integer> m2 = new HashMap<String, Integer>();
        List<Integer> f1 = new ArrayList<Integer>();
        List<Integer> f2 = new ArrayList<Integer>();
        
        int ct = 0;
        for (int i = 0, len = pattern.length(); i < len; ++ i) {
            //if (! m1.containsKey(pattern.charAt(i))) { 
            if (m1.get(pattern.charAt(i)) == null) {
                m1.put(pattern.charAt(i), ++ ct);
            }
            f1.add(m1.get(pattern.charAt(i)));
        }
        
        try 
        {
            String[] s = str.split(" ");
            ct = 0;
            for (int i = 0, len = s.length; i < len; ++ i) {
                if (m2.get(s[i]) == null) {
                    m2.put(s[i], ++ ct);
                }
                f2.add(m2.get(s[i]));
            };
        } catch (Exception e) {
            
        }

        if (f1.size() != f2.size()) return false;

        for (int i = 0, len = f1.size(); i < len; ++ i) {
            if (f1.get(i) != f2.get(i)) return false;
        }

        return true;
    }
    
    /*
    private void dumpList(List<Integer> v) {
        for (int i = 0, len = v.size(); i < len; ++ i) {
            System.out.print(v.get(i) + " ");
        }
        System.out.println("");
    }
    */
}


/**
Word Pattern
Difficulty: Easy

Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a 
letter in pattern and a non-empty word in str.

Examples:

    pattern = "abba", str = "dog cat cat dog" should return true.
    pattern = "abba", str = "dog cat cat fish" should return false.
    pattern = "aaaa", str = "dog cat cat dog" should return false.
    pattern = "abba", str = "dog dog dog dog" should return false.

Notes:
You may assume pattern contains only lowercase letters, and str contains 
lowercase letters separated by a single space. 
 */
