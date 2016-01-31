// Works. 
// Modified from: https://leetcode.com/discuss/82185/c-straightforward-solution
class Solution {
public:
    bool isAdditiveNumber(string num, string last1, string last2) {
         if ((num[0] == '0' && num.length() > 1) || 
             (last1[0] == '0' && last1.length() > 1) || 
             (last2[0] == '0' && last2.length() > 1))
        return false;
    
        long long sum = stoll(last1) + stoll(last2);
        int len = (int)log10(sum) + 1;
        if (sum != stoll(num.substr(0, len))) return false;
        //if (num.substr(len).length() == 0) return true;
        if (len == num.length()) return true;
        
        return isAdditiveNumber(num.substr(len), last2, num.substr(0, len));
    }
    
    bool isAdditiveNumber(string num) {
        for (int i = 1; i < num.length(); ++ i) {
            for (int j = 1, lenj = num.length() - i; j < lenj; ++ j) {
                if (isAdditiveNumber(num.substr(i + j), num.substr(0, i), num.substr(i, j)))
                    return true;
            }
        }
    
        return false;
    }
};


/**
Additive Number
Difficulty: Medium

Additive number is a string whose digits can form additive sequence.

A valid additive sequence should contain at least three numbers. 
Except for the first two numbers, each subsequent number in the 
sequence must be the sum of the preceding two.

For example:
"112358" is an additive number because the digits can form an 
additive sequence: 1, 1, 2, 3, 5, 8.

1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8

"199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199.

1 + 99 = 100, 99 + 100 = 199

Note: Numbers in the additive sequence cannot have leading zeros, 
so sequence 1, 2, 03 or 1, 02, 3 is invalid.

Given a string containing only digits '0'-'9', write a function 
to determine if it's an additive number.

Follow up:
How would you handle overflow for very large input integers? 
 */
