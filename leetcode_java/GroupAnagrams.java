public class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> ans = new ArrayList<List<String>>();
        
        HashMap<String, ArrayList<String>> m = new HashMap<String, ArrayList<String>>();
        for (int i = 0, len = strs.length; i < len; ++ i) {
            char a[] = strs[i].toCharArray();
            Arrays.sort(a);
            String key = String.valueOf(a); // convert char array to String.

            if (! m.containsKey(key)) m.put(key, new ArrayList<String>());
            m.get(key).add(strs[i]);
        }
        
        Iterator<String> it = m.keySet().iterator();
        while ( it.hasNext() ) {
            ArrayList<String> v = m.get(it.next());
            Collections.sort(v);
            ans.add(v);
        }
        
        return ans;        
    }
}

/**
Group Anagrams
Difficulty: Medium

Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note:

    For the return value, each inner list's elements must follow the lexicographic order.
    All inputs will be in lower-case.
 */
