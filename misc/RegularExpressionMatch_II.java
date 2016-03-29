public class RegularExpressionMatch_II {
    public boolean match(String s, String p) {
        return match(s, 0, p, 0);
    }
    private boolean match(String s, int i, String p, int j) {
        if (j == p.length()) return i == s.length();

        if (j + 1 < p.length() && p.charAt(j + 1) == '*') {
            // match(s+1, p) - match next char in s.
            // match(s, p+2) - match exactly nothing in s.
            if (i < s.length() && s.charAt(i) == p.charAt(j))
                return match(s, i + 1, p, j) || match(s, i, p, j + 2);
            else
                return match(s, i, p, j + 2); // matches exactly nothing in s.
        } else if (j + 1 < p.length() && p.charAt(j + 1) == '+') {
            // match(s+1, p) - match next char in s.
            // match(s+1, p+2) - match exactly 1 char in s.
            if (i < s.length() && s.charAt(i) == p.charAt(j))
                return match(s, i + 1, p, j) || match(s, i + 1, p, j + 2);
            else
                return false;
        } else if (i < s.length() && s.charAt(i) == p.charAt(j)) {
            return match(s, i + 1, p, j + 1); // match exactly 1 char in s.
        } else {
            return false;
        }
    }
    public static void main(String args[]) {
        test("aab", "a+b", true);//true
        test("aab", "aab", true);//true
        test("aab", "aa*b", true);//true
        test("aab", "a+b*", true);//true
        test("aab", "aa+b", true);//true
        test("aab", "a+b+", true);//true
        test("aab", "a+b*", true);//true
        test("aab", "aaa+b", false);//false
        test("aab", "a+bb+", false);//false
    }
    static void test(String s, String p, boolean expect) {
        System.out.println("expect: " + expect + ", is: " + sol.match(s, p));
    }
    static RegularExpressionMatch_II sol = new RegularExpressionMatch_II();
}
