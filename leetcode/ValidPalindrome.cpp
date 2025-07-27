// Works. Tested. Similar to Solution4.
class Solution5 {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        for (; i < j; ++ i, -- j) {
            while (i < j && !isalnum(s[i])) ++ i;
            while (i < j && !isalnum(s[j])) -- j;
            if (tolower(s[i]) != tolower(s[j])) return false;
        }
        return true;
    }
};

// Works. Tested. Best answer.
// Use standard functions isalnum(), tolower(), toupper() in <cctype>.
class Solution4 {
public:
    bool isPalindrome(string s) {
        int L = 0, R = s.length() - 1;
        
        while (L < R) {
            if (! isalnum(s[L])) ++ L;
            else if (! isalnum(s[R])) -- R;
            else {
                if (tolower(s[L]) != tolower(s[R])) return false;
                ++ L, -- R; // don't forget this.
            }
        }
        
        return true;
    }
};


//
// This works too.
//
class Solution3 {
public:
    bool isPalindrome(string s) {
        if (s.length() == 0) return true;
        
        int L = 0, R = s.length() - 1;
        
        while (L < R) {
            while (! isAN(s[L]) && L < R) ++ L;
            while (! isAN(s[R]) && L < R) -- R;
            
            if (toLower(s[L]) != toLower(s[R])) return false;
            ++ L, -- R;
        }
        
        return true;
    }
    
    bool isAN(char c) {
        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
    }
    
    char toLower(char c) {
        if (c >= 'A' && c <= 'Z') {
            return c - 'A' + 'a';
        }
        return c;
    }
};


//
// This works too, and is better.
//
class Solution2 {
public:
    bool isPalindrome(string s) {
        for (int L = 0, R = s.length() - 1; L < R; ) {
           if (! isalnum(s[L]) ) {
               ++ L;
           }
           else if (! isalnum(s[R]) ) {
               -- R;
           }
           else {
               if ( lcase(s[L ++ ]) != lcase(s[R --]) ) {
                   return false;
               }
           }
        }
        
        return true;
    }
    
    bool isalnum(char c) {
        return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }
    
    char lcase(char c) {
        if (c >= 'A' && c <= 'Z') {
            return c - 'A' + 'a';
        }
        else {
            return c;
        }
    }
};


class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.length();
        //if (len == 0) return true;
        
        int i = 0, j = len - 1;
        while (i < j) {
            while (! isAN(s[i]) && i <= len-1 && i < j) ++ i; // NOTE: i <= len-1 is needed!
            while (! isAN(s[j]) && j >= 0 && i < j) -- j;     // NOTE: j >= 0 is needed!
            if (i > j) break; 
            
            if (toLC(s[i]) != toLC(s[j])) return false;
            ++ i;
            -- j;
        }
        
        return true;
    }
    
    char toLC(char c) {
        if (c >= 'A' && c <= 'Z') return c - 'A' + 'a';
        return c;
    }
    
    bool isAN(char c) {
        if (c >= 'a' && c <= 'z') return true;
        if (c >= 'A' && c <= 'Z') return true;
        if (c >= '0' && c <= '9') return true;
        return false;
    }   
    
};


/*
Problem:
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
 */
