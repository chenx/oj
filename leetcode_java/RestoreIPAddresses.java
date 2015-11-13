public class Solution {
    public List<String> restoreIpAddresses(String s) {
        List<String> ans = new ArrayList<String>();
        
        int len = s.length();
        for (int i = 1; i <= 3; ++ i) {
            for (int j = 1; j <= 3; ++ j) {
                for (int k = 1; k <= 3; ++ k) {
                    if (i + j + k >= len) continue;
                    
                    String s1 = s.substring(0, i);
                    String s2 = s.substring(i, i + j);
                    String s3 = s.substring(i + j, i + j + k);
                    String s4 = s.substring(i + j + k);
                    
                    if (isValidIP(s1) && isValidIP(s2) && isValidIP(s3) && isValidIP(s4)) {
                        ans.add(s1 + "." + s2 + "." + s3 + "." + s4);
                    }
                }
            }
        }
        
        return ans;
    }
    
    private boolean isValidIP(String s) {
        if (s.length() >= 2 && s.charAt(0) == '0') return false;
        
        int ip = 0;
        for (int i = 0, len = s.length(); i < len; ++ i) {
            ip = ip * 10 + (s.charAt(i) - '0');
        }
        
        return ip >= 0 && ip <= 255;
    }
}

/**
Restore IP Addresses
Difficulty: Medium

Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter) 
 */
