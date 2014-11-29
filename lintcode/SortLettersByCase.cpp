//
// Both methods work.
// They are also in one-pass and in-pace.
//
class Solution {
public:
    /** 
     * @param chars: The letters array you should sort.
     */
    void sortLetters2(string &letters) {
        // write your code here
        int L = 0, R = letters.length() - 1;
        
        while (L < R) {
            while (letters[L] >= 'a' && letters[L] <= 'z') ++ L;
            while (letters[R] <= 'Z' && letters[R] >= 'A') -- R;
            
            if (L < R) {
                swap(letters[L], letters[R]);
                ++ L, -- R;
            }
        }
    }
    
    void sortLetters(string &letters) {
        // write your code here
        int L = 0, R = letters.length() - 1;
        
        while (L < R) {
            if (letters[L] >= 'a' && letters[L] <= 'z') ++ L;
            else if (letters[R] <= 'Z' && letters[R] >= 'A') -- R;
            else {
                swap(letters[L], letters[R]);
                ++ L, -- R;
            }
        }
    }    
};

/**
Sort Letters by Case

Given a string which contains only letters. Sort it by lower case first and upper case second.

Note:
It's not necessary to keep the original order of lower-case letters and upper case letters.

E.g.,
For "abAcD", a reasonable answer is "acbAD"

Challenge: Do it in one-pass and in-place.
 */
