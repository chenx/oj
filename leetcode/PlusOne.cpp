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
