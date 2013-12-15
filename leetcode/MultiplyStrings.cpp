//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 1/9/2013
// @Last modified: 1/9/2013
//

// Method:
// Multiply each digit of num2 with num1, add to product with 0 padding.
//
class Solution {
public:
    string multiply(string num1, string num2) {
        // store result in a vector, 0 for lowest bit; write back to a string in reverse order.
        vector<int> prod;
        for (int i = num1.size() - 1; i >= 0; -- i) {
            // multiple num1[i] with num2 and add result to v.
            vector<int> tmp = multi_digit(num2, num1[i], (num1.size() - 1) - i);
            // add tmp to prod.
            add_digit(prod, tmp);
        }
        
        return vec2str(prod);
    }
    
    // v: [0...n] -> lower digits to higher digits.
    string vec2str(vector<int> v) {
        string s = "";
        bool zero_head = true;
        for (int i = v.size() - 1; i >= 0; -- i) {
            if (zero_head) { 
                if (v[i] == 0) continue; // ignore starting 0s.
                else zero_head = false;
            }
            s += v[i] + '0';
        }
        if (s == "") s = "0"; // don't forget this!
        
        return s;        
    }
    
    void add_digit(vector<int> &prod, vector<int> &tmp) {
        if (prod.size() == 0) { // Good but not necessary. Faster though.
            prod = tmp;
        } else {
            int carry = 0, sum, i = 0, j = 0;
            for (; i < prod.size() && j < tmp.size(); ++i, ++j) {
                sum = prod[i] + tmp[j] + carry;
                prod[i] = sum % 10;
                carry = sum / 10;
            }
            
            for (; i < prod.size(); ++ i) {
                sum = prod[i] + carry;
                prod[i] = sum % 10;
                carry = sum / 10;
            }

            for (; j < tmp.size(); ++ j) {
                sum = tmp[j] + carry;
                prod.push_back(sum % 10);
                carry = sum / 10;
            }

            if (carry != 0) prod.push_back(carry); // don't forget this!
        }
    }
    
    vector<int> multi_digit(string n, char m, int padding) {
        vector<int> v;
        for (int i = 0; i < padding; ++ i) { // pad 0s: shift tmp num1.size() - i - 1 digits right.
            v.push_back(0);
        }
        
        int mv = m - '0', x, carry = 0;
        for (int i = n.length() - 1; i >= 0; -- i) {
            x = (n[i] - '0') * mv + carry;
            v.push_back(x % 10);
            carry = x / 10;
        }
        
        if (carry != 0) v.push_back(carry); // don't forget this!
        
        return v;
    }
};



//
// This also works, but times out for large test set. The first version is more efficient.
//
class Solution2 {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.length();
        int n2 = num2.length();
        
        if (n1 < n2) return multiply(num2, num1);
        
        string ans = "0";
        for (int i = n2 - 1; i >= 0; -- i) {
            string m = mul(num1, num2[i]);
            ans = sum(ans, m, n2 - 1 - i); // i: shift m left by i digits.
        }
        
        return ans;
    }
    
    inline string mul(string num, char c) {
        int m, carry = 0;
        string ans = "0";
        for (int i = num.length() - 1; i >= 0; -- i) {
            m = (c - '0') * (num[i] - '0') + carry;
            carry = m / 10;
            m = m % 10;
            
            ans = sum(ans, int2str(m), num.length() - i - 1);
        }
        
        if (carry > 0) {
            ans = sum(ans, int2str(carry), num.length());
        }
        return ans;
    }
    
    inline string int2str(int n) {
        stringstream ss;
        ss << n;
        return ss.str();
    }
    
    inline string sum(string x, string y, int yshift) {
        if (y == "0") return x;
    
        y = y + string(yshift, '0');
        if (x == "0") return y;
        
        if (x.length() > y.length()) return sum(x, y);
        else return sum(y, x);
    }
    
    inline string sum(string x, string y) {
        string ans = "";
        
        int sum, carry = 0, i, j;
        for (i = x.length() - 1, j = y.length() - 1; j >= 0; -- i, -- j) {
            sum = (x[i] - '0') + (y[j] - '0') + carry;
            carry = 0;
            
            if (sum >= 10) {
                carry = 1; //sum / 10;
                sum -= 10;
            }
            
            ans = int2str(sum) + ans;
        }
        
        for (; i >= 0; -- i) {
            sum = x[i] - '0' + carry;
            carry = 0;

            if (sum >= 10) {
                carry = 1; //sum / 10;
                sum -= 10;
            }
            
            ans = int2str(sum) + ans;
        }
        
        if (carry > 0) {
            ans = int2str(carry) + ans;
        }
        
        return ans;
    }
};



/*
Problem:
Given two numbers represented as strings, return multiplication of the numbers as a string.
Note: The numbers can be arbitrarily large and are non-negative.
 */
