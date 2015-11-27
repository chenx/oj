// This works.
// Use recusion.
// From: https://leetcode.com/discuss/57994/simple-backtracking-java-solution-with-95%25-performance
public class Solution2 {
    public List<List<String>> partition(String s) {
        List<List<String>> res = new ArrayList<List<String>>();
        if (s.equals("")) {
            res.add(new ArrayList<String>());
            return res;
        }
        for (int i = 0; i < s.length(); i++) {
            if (isPalindrome(s, i + 1)) {
                for (List<String> list : partition(s.substring(i+1))) {
                    list.add(0, s.substring(0, i + 1));
                    res.add(list);
                }
            }
        }
        return res;
    }

    public boolean isPalindrome(String s, int n) {
        for (int i = 0; i < n / 2; i++) {
            if (s.charAt(i) != s.charAt(n - i - 1))
                return false;
        }
        return true;
    }
}

// This should work. But times out for large input.
public class Solution {
    public List<List<String>> partition(String s) {
        if (s.equals("")) return null;
        int n = s.length();
        //ArrayList<List<String>> ans[] = new ArrayList<List<String>[n];
        List<List<List<String>>> ans = new ArrayList<List<List<String>>>();

        for (int i = 0; i < n; ++ i) {
            ans.add(new ArrayList<List<String>>());
            // check substring s.substring(0, i).
            String t = s.substring(0, i);
            if (isPalindrome(t)) {
                List<String> v = new ArrayList<String>();
                v.add(t);
                ans.get(i).add(v);
            }
            
            for (int j = i; j > 0; -- j) {
                t = s.substring(j, i);
                if (isPalindrome(t)) {
                    for (int k = 0, lenk = ans.get(j - 1).size(); k < lenk; ++ k) {
                        //List list2 = ((List) ( (ArrayList) list).clone());
                        List<String> v = (List) ((ArrayList) ans.get(j - 1).get(k)).clone();
                        v.add(t);
                        ans.get(i).add(v);
                    }
                }
            }
        }
        
        return ans.get(n-1);        
    }
    
    boolean isPalindrome(String t) {
        int L = 0, R = t.length() - 1;
        while (L < R) {
            if (t.charAt(L) != t.charAt(R)) return false;
            ++ L; -- R;
        }
        return true;
    }
}

/**
Palindrome Partitioning
Difficulty: Medium

Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
 */
