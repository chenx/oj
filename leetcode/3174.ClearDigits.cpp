// t is similar to using a stack.
class Solution {
public:
    string clearDigits(string s) {
        string t;
        for (int i = 0; i < s.length(); ++ i) {
            if (isdigit(s[i])) {
                if (t != "") t.pop_back();
            } else {
                t += s[i];
            }
        }
        return t;
    }
};

/**
3174. Clear Digits
Easy

You are given a string s.

Your task is to remove all digits by doing this operation repeatedly:

    Delete the first digit and the closest non-digit character to its left.

Return the resulting string after removing all digits.

Note that the operation cannot be performed on a digit that does not have any non-digit character to its left.
 */
