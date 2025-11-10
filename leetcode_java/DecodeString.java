// 2 stack solutions. Works.
// Time Complexity: O(maxK⋅n), where maxK is the maximum value of k and n is the length of a given string s. 
// Space Complexity: O(m+n), where m is the number of letters(a-z) and n is the number of digits(0-9) in string s. 
//   In worst case, the maximum size of stringStack and countStack could be m and n respectively.
//
class Solution2 {
    public String decodeString(String s) {
        Stack<Integer> numStack = new Stack<>();
        Stack<StringBuilder> strStack = new Stack<>();

        int k = 0;
        StringBuilder cur = new StringBuilder();
        for (int i = 0; i < s.length(); ++ i) {
            char ch = s.charAt(i);
            if (Character.isDigit(ch)) {
                k = k * 10 + (ch - '0');
            } else if (ch == '[') {
                numStack.push(k);
                strStack.push(cur);
                k = 0;
                cur = new StringBuilder();
            } else if (ch == ']') {
                StringBuilder sb = strStack.pop();
                for (int ct = numStack.pop(); ct > 0; -- ct) {
                    sb.append(cur);  // NOTE: append cur
                }
                cur = sb;
            } else {
                cur.append(ch);
            }
        }
        return cur.toString();
    }
}


class Solution {
    String decodeString(String s) {
        Stack<Integer> countStack = new Stack<>();
        Stack<StringBuilder> stringStack = new Stack<>();
        StringBuilder currentString = new StringBuilder();
        int k = 0;
        for (char ch : s.toCharArray()) {
            if (Character.isDigit(ch)) {
                k = k * 10 + ch - '0';
            } else if (ch == '[') {
                // push the number k to countStack
                countStack.push(k);
                // push the currentString to stringStack
                stringStack.push(currentString);
                // reset currentString and k
                currentString = new StringBuilder();
                k = 0;
            } else if (ch == ']') {
                StringBuilder decodedString = stringStack.pop();
                // decode currentK[currentString] by appending currentString k times
                for (int currentK = countStack.pop(); currentK > 0; currentK--) {
                    decodedString.append(currentString);
                }
                currentString = decodedString;
            } else {
                currentString.append(ch);
            }
        }
        return currentString.toString();
    }
}

/**
394. Decode String
Medium

Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is 
being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square 
brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain 
any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 105.
 */
