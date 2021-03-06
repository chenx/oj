//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 1/9/2013
// @Last modified: 1/9/2013
//

// Works too.
class Solution4 {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0"; // note this, to avoid sth like "0000".
        
        string ans = "0";
        for (int i = num2.size() - 1; i >= 0; -- i) {
            ans = add (ans, shift_left(mul(num1, num2[i]), num2.size() - 1 - i));
        }
        return ans;
    }
    
    string mul(string n, char c) {
        string ans;
        int carry = 0;
        for (int i = n.length() - 1; i >= 0; -- i) {
            add( (n[i] - '0') * (c - '0') + carry, carry, ans );
        }
        if (carry > 0) {
            //char c = '0' + carry;
            ans = to_string(carry) + ans; // ans = c + ans works too.
        }
        return ans;
    }
    
    void add(int val, int &carry, string & ans) {
        if (val >= 10) {
            carry = val / 10; // this goes before val %= 10.
            val %= 10; 
        }
        else {
            carry = 0;
        }
        //char c = val + '0';
        ans = to_string(val) + ans; // ans = c + ans works too.
    }
    
    string shift_left(string n, int pos) {
        return n + string(pos, '0');
    }
    
    string add(string a, string b) {
        string sum;
        int ai = a.length() - 1, bi = b.length() - 1, carry = 0;
        for (; ai >= 0 && bi >= 0; -- ai, -- bi) {
            add(a[ai] - '0' + b[bi] - '0' + carry, carry, sum);
        }
        for (; ai >= 0; -- ai) {
            add(a[ai] - '0' + carry, carry, sum);
        }
        for (; bi >= 0; -- bi) {
            add(b[bi] - '0' + carry, carry, sum);
        }
        if (carry > 0) {
            add(carry, carry, sum);
        }
        return sum;
    }
};

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

// This works too. May be most clean. 11/11/2014
class Solution3 {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        
        string sum = "0";
        for (int i = 0, n = num2.length(); i < n; ++ i) {
            string t = mult(num1, num2[i] - '0');
            sum = add(sum, shift_left(t, n-1-i));
        }
        return sum;
    }
    
    string mult(string s, int c) {
        int carry = 0;
        string p = "";
        for (int i = s.length() - 1; i >= 0; -- i) {
            int prod = c * (s[i] - '0') + carry;
            if (prod >= 10) {
                carry = prod / 10;
                prod = prod % 10;
            }
            else {
                carry = 0;
            }
            p = m_char(prod) + p;
        }
        if (carry > 0) {
            p = m_char(carry) + p;
        }
        return p;
    }
    
    string shift_left(string s, int pos) {
        while (pos > 0) {
            s = s + "0";
            -- pos;
        }
        return s;
    }
    
    string add(string a, string b) {
        int carry = 0, i, j;
        string sum = "";
        for (i = a.length()-1, j = b.length()-1; i >= 0 && j >= 0; -- i, -- j) {
            add_digit(sum, a[i] - '0' + b[j] - '0' + carry, carry);
        }
        for (; i >= 0; -- i) {
            add_digit(sum, a[i] - '0' + carry, carry);
        }
        for (; j >= 0; -- j) {
            add_digit(sum, b[j] - '0' + carry, carry);
        }
        if (carry > 0) {
            sum = m_char(carry) + sum;
        }
        return sum;
    }
    
    void add_digit(string & sum, int n, int &carry) {
        if (n >= 10) {
            carry = 1;
            n -= 10;
        }
        else {
            carry = 0;
        }
        sum = m_char(n) + sum;
    }
    
    char m_char(int i) {
        return i + '0';
    }
};


/*
Problem:
Given two numbers represented as strings, return multiplication of the numbers as a string.
Note: The numbers can be arbitrarily large and are non-negative.
 */
