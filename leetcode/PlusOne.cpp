//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/24/2012
// @Last modified: 12/24/2012
//

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // digits: pos 0 is at highest bit.
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; i --) {
            digits[i] += carry;
            if (digits[i] >= 10) { 
                carry = 1;
                digits[i] -= 10;
            }
            else {
                carry = 0;
                break;
            }
        }
        
        if (carry > 0) {
            digits.insert(digits.begin(), carry);
        }
        
        return digits;        
    }
};

// This works too.
class Solution2 {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size(), carry = 1;
        
        for (int i = len - 1; i >= 0; -- i) {
            digits[i] += carry;
            if (digits[i] >= 10) {
                digits[i] -= 10;
                carry = 1;
            }
            else {
                return digits;
            }
        }
        
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
