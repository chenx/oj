// Use a stack, if new char equals stack.top(), pop stack.top(); otherwise push to stack.
// Time O(N), Space O(N−D) where D is a total length for all duplicates.
class Solution2 {
    public String removeDuplicates(String s) {
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < s.length(); ++ i) {
            // Note: cannot use s[i] here, which is a string, not a char.
            if (!sb.isEmpty() && sb.charAt(sb.length() - 1) == s.charAt(i)) {
                sb.deleteCharAt(sb.length() - 1);
            } else {
                sb.append(s.charAt(i));
            }
        }

        return sb.toString();
    }
}

// Time: O(n^2), Space: O(n^2)
// Times out for large input.
class Solution {
    public String removeDuplicates(String s) {
        HashSet<String> set = new HashSet<>();
        for (char i = 'a'; i <= 'z'; ++ i) {
            set.add("" + i + i);
        }

        while (true) {
            int len = s.length();
            for (String entry : set) {
                s = s.replace(entry, "");
            }
            if (len == s.length()) break;
        }

        return s;
    }
}

/**
1047. Remove All Adjacent Duplicates In String
Easy

You are given a string s consisting of lowercase English letters. 
A duplicate removal consists of choosing two adjacent and equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. 
It can be proven that the answer is unique.
 */
