public class Solution {
    public boolean isPalindrome(String s) {
        int L = 0, R = s.length() - 1;
        
        while (L < R) {
            if (! isAlnum(s.charAt(L))) ++ L;
            else if (! isAlnum(s.charAt(R))) -- R;
            else {
                if (toLower(s.charAt(L)) != toLower(s.charAt(R))) return false;
                ++ L; -- R;
            }
        }
        
        return true;
    }
    
    private char toLower(char c) {
        if (c >= 'A' && c <= 'Z') c = (char) (c - 'A' + 'a'); // must cast here!
        return c;
    }
    
    private boolean isAlnum(char c) {
        return (c >= '0' && c <= '9')
            || (c >= 'a' && c <= 'z')
            || (c >= 'A' && c <= 'Z');
    }
}

/**
Valid Palindrome
Difficulty: Easy

Given a string, determine if it is a palindrome, considering only 
alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good 
question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome. 
 */
