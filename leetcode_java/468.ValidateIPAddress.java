class Solution {
    public String validIPAddress(String queryIP) {
        if (isValidIPv4(queryIP)) return "IPv4";
        if (isValidIPv6(queryIP)) return "IPv6";
        return "Neither";
    }

    private boolean isValidIPv4(String queryIP) {
        if (queryIP.endsWith(".")) return false;  // E.g., "1.1.1.1."

        String[] nums = queryIP.split("\\.");  // Split uses regular expression; escape "."
        if (nums.length != 4) return false;
        for (int i = 0; i < 4; ++ i) {
            String s = nums[i];
            int len = s.length();
            if (len == 0 || len > 3) return false;
            if (len > 1 && s.charAt(0) == '0') return false;

            int val = 0;
            for (int j = 0; j < len; ++ j) {
                if (! isDigit(s.charAt(j))) return false;
                val = val * 10 + (s.charAt(j) - '0');
            }
            if (val > 255) return false;
        }
        return true;
    }

    private boolean isValidIPv6(String queryIP) {
        if (queryIP.endsWith(":")) return false;  // E.g., "1:1:1 ... :1:"

        String[] nums = queryIP.split(":"); 
        if (nums.length != 8) return false;
        for (int i = 0; i < 8; ++ i) {
            String s = nums[i];
            int len = s.length();
            if (len == 0 || len > 4) return false;

            for (int j = 0; j < len; ++ j) {
                if (! isHexadecimal(s.charAt(j))) return false;
            }
        }
        return true;
    }

    private boolean isDigit(char ch) {
        return ch >= '0' && ch <= '9';
    }

    private boolean isHexadecimal(char ch) {
        return isDigit(ch) || (ch >= 'a' && ch <= 'f') || (ch >= 'A' && ch <= 'F');
    }
}


/**
468. Validate IP Address
Medium

Given a string queryIP, return "IPv4" if IP is a valid IPv4 address, "IPv6" if IP is a valid IPv6 address or "Neither" 
if IP is not a correct IP of any type.

A valid IPv4 address is an IP in the form "x1.x2.x3.x4" where 0 <= xi <= 255 and xi cannot contain leading zeros. 
For example, "192.168.1.1" and "192.168.1.0" are valid IPv4 addresses while "192.168.01.1", "192.168.1.00", and 
"192.168@1.1" are invalid IPv4 addresses.

A valid IPv6 address is an IP in the form "x1:x2:x3:x4:x5:x6:x7:x8" where:

    1 <= xi.length <= 4
    xi is a hexadecimal string which may contain digits, lowercase English letter ('a' to 'f') and upper-case English letters ('A' to 'F').
    Leading zeros are allowed in xi.

For example, "2001:0db8:85a3:0000:0000:8a2e:0370:7334" and "2001:db8:85a3:0:0:8A2E:0370:7334" are valid IPv6 addresses, 
while "2001:0db8:85a3::8A2E:037j:7334" and "02001:0db8:85a3:0000:0000:8a2e:0370:7334" are invalid IPv6 addresses.
 */
