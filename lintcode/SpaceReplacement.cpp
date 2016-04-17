class Solution {
public:
    /**
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
        int ct = 0; // count of space.
        for (int i = 0; i < length; ++ i) {
            if (string[i] == ' ') ++ ct;
        }
        
        int len  = length + ct * 2, m = len - 1;
        
        for (int n = length - 1; n >= 0; -- n) {
            if (string[n] == ' ') {
                string[m-2] = '%';
                string[m-1] = '2';
                string[m] = '0';
                m -= 3;
            }
            else {
                string[m --] = string[n];
            }
        }
        
        return len;
    }
};  


/**
Space Replacement

Write a method to replace all spaces in a string with %20. The string is given 
in a characters array, you can assume it has enough space for replacement and 
you are given the true length of the string.

You code should also return the new length of the string after replacement.
Have you met this question in a real interview?
Notice

If you are using Java or Python，please use characters array instead of string.
Example

Given "Mr John Smith", length = 13.

The string after replacement should be "Mr%20John%20Smith".
Challenge

Do it in-place.

 */
