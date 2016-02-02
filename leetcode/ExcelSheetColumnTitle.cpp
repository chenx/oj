//
// This works.
//
class Solution {
public:
    string convertToTitle(int n) {
        string s = "";
        
        while (n > 0) {
            char c = (n - 1) % 26 + 'A';
            s = c + s; // be careful here. If use string(c), will have error: cannot convert char to const char *.
            n = (n - 1) / 26;
        }
        
        return s;
    }
};

/**
Excel Sheet Column Title 
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
 */
