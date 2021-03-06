//
// http://www.leetcode.com/onlinejudge#
// 3sum.
// @Author: Xin Chen
// @Created on: 12/13/2012
// @Last modified: 3/22/2012
//

#include <string>
#include <iostream>
using namespace std;

// Works too.
class Solution6 {
public:
    string addBinary(string a, string b) {
        string ans;
        
        int n1 = a.length() - 1, n2 = b.length() - 1, carry = 0;
        
        for (; n1 >= 0 && n2 >= 0; -- n1, -- n2) 
            add(a[n1] - '0' + b[n2] - '0' + carry, carry, ans);
        for (; n1 >= 0; -- n1) 
            add(a[n1] - '0' + carry, carry, ans);
        for (; n2 >= 0; -- n2) 
            add(b[n2] - '0' + carry, carry, ans);
        if (carry > 0) 
            add(carry, carry, ans);
        
        return ans;
    }
    
    void add(int sum, int & carry, string & ans) {
        if (sum >= 2) sum -= 2, carry = 1;
        else carry = 0;

        ans = to_string(sum) + ans;
    }
};

// Works. Best answer so far. Concise.
class Solution5 {
public:
    string addBinary(string a, string b) {
        string ans;
        
        int n1 = a.length(), n2 = b.length(), len = min(n1, n2), carry = 0, i;
        
        for (i = 1; i <= len; ++ i) 
            add(a[n1 - i] - '0' + b[n2 - i] - '0' + carry, carry, ans);
        
        for (; i <= n1; ++ i) 
            add(a[n1 - i] - '0' + carry, carry, ans);
            
        for (; i <= n2; ++ i) 
            add(b[n2 - i] - '0' + carry, carry, ans);
            
        if (carry == 1) 
            add(1, carry, ans);
        
        return ans;
    }
    
    void add(int sum, int &carry, string &ans) {
        if (sum >= 2) {
            sum -= 2;
            carry = 1;
        }
        else {
            carry = 0;
        }
        
        ans = to_string(sum) + ans;
    }
};

// Second version, use char array. 
// Note use string would be inconvenient.
class Solution {
public:
    string addBinary(string a, string b) {
        if (a.length() == 0) return b;
        if (b.length() == 0) return a;
        
        int len_a = a.length();
        int len_b = b.length();
        //printf("len_a = %d, len_b = %d\n", len_a, len_b);
        int len = (len_a > len_b) ? len_a : len_b;
        len += 2; // for carry bit, and tail '\0'.
        char * s = (char *) malloc(len * sizeof(char)); 
        // use "string s = new string[len];" would be very inconvenient.
        int p = 0;
        
        //string s;
        int sum, carry = 0;
        for (-- len_a, -- len_b; len_a >= 0 && len_b >= 0; --len_a, --len_b) {
            add( (a[len_a] - '0') + (b[len_b] - '0') + carry, &sum, &carry );
            s[p ++] = sum + '0';
        }
        
        for ( ; len_a >= 0; -- len_a) {
            add( (a[len_a] - '0') + carry, &sum, &carry );
            s[p ++] = sum + '0';
        }
        
        for ( ; len_b >= 0; -- len_b) {
            add( (b[len_b] - '0') + carry, &sum, &carry );
            s[p ++] = sum + '0';
        }

        if (carry == 1) {
            s[p ++] = '1';
        }
        
        s[p] = '\0';
        
        string t = string(s);        
        reverse(t.begin(), t.end());        
        return t;
    }
    
    void add(int val, int *sum, int *carry) {
        if (val == 3) {
            *sum = 1;
            *carry = 1;
        } else if (val == 2) {
            *sum = 0;
            *carry = 1;
        } else {
            *sum = val;
            *carry = 0;
        }
    }
};


//
// This also works.
//
class Solution2 {
public:
    string addBinary(string a, string b) {
        int lena = a.length();
        int lenb = b.length();
        
        if (lena < lenb) return addBinary(b, a); // note this.
        
        // a.length() >= b.length().
        string c = "";
        int sum, carry = 0, i, j;
        for (i = lenb - 1, j = lena - 1; i >= 0; -- i, -- j) {
            add((b[i] - '0') + (a[j] - '0') + carry, sum, carry);
            c = (char)(sum + '0') + c;
        }
        
        for (; j >= 0; -- j) {
            add((a[j] - '0') + carry, sum, carry);
            c = (char)(sum + '0') + c;
        }
        
        if (carry > 0) {
            c = (char)(carry + '0') + c;
        }
        
        return c;
    }
    
    void add(int v, int & sum, int & carry) {
        sum = v;
        carry = 0;
        if (sum >= 2) {
            sum -= 2;
            carry = 1;
        }
    }
};


// This also works. And seems most clean. 10/26/2014
// Note this can be easily extended to calculate addition for different base:
//   just change the cutoff value in function add():
//   when it's 2, it's binary addition; when it's 10, it's decimal; 
//   it can also be base-14 or any base.
// Basically, this is one solution to large number addition.
class Solution3 {
public:
    string addBinary(string a, string b) {
        int carry = 0, sum = 0;
        string c;
        
        int i = a.length() - 1, j = b.length() - 1;
        while (i >= 0 && j >= 0) {
            add(a[i --] - '0' + b[j --] - '0' + carry, carry, c);
        }
        while (i >= 0) {
            add(a[i --] - '0' + carry, carry, c);
        }
        while (j >= 0) {
            add(b[j --] - '0' + carry, carry, c);
        }
        
        if (carry > 0) { c = "1" + c; }
        return c;
    }
    
    void add(int sum, int &carry, string &c) {
        if (sum >= 2) {
            sum -= 2;
            carry = 1;
        }
        else {
            carry = 0;
        }
        
        char x = sum + '0';
        c = x + c;
    }
};

// This works.
class Solution4 {
public:
    string addBinary(string a, string b) {
        int lena = a.length() - 1, lenb = b.length() - 1;
        int sum = 0, carry = 0;
        
        string v = "";
        for (; lena >= 0 && lenb >= 0; -- lena, -- lenb) {
            add(a[lena] - '0', b[lenb] - '0', sum, carry);
            v = to_string(sum) + v;
        }
        for (; lena >= 0; -- lena) {
            add(a[lena] - '0', 0, sum, carry);
            v = to_string(sum) + v;
        }
        for (; lenb >= 0; -- lenb) {
            add(0, b[lenb] - '0', sum, carry);
            v = to_string(sum) + v;
        }

        if (carry > 0) {
            v = to_string(carry) + v;
        }
        
        return v;
    }
    
    void add(int a, int b, int &sum, int &carry) {
        sum = a + b + carry;
        if (sum > 1) {
            sum -= 2;
            carry = 1;
        }
        else {
            carry = 0;
        }
    }
};

/* 
// First version. This works.
class Solution {
public:
    string addBinary(string a, string b) {
        if (a.length() == 0) return b;
        if (b.length() == 0) return a;
        
        int len_a = a.length();
        int len_b = b.length();
        //printf("len_a = %d, len_b = %d\n", len_a, len_b);
        
        string s;
        int sum, carry = 0;
        char c[2]; 
        c[1] = 0; // if c[] does not end with \0, string += c will be giberish.
        for (-- len_a, -- len_b; len_a >= 0 && len_b >= 0; --len_a, --len_b) {
            add( (a[len_a] - '0') + (b[len_b] - '0') + carry, &sum, &carry );
            c[0] = sum + '0';
            s += string(c);
        }
        
        for ( ; len_a >= 0; -- len_a) {
            add( (a[len_a] - '0') + carry, &sum, &carry );
            c[0] = sum + '0';
            s += string(c);            
        }
        
        for ( ; len_b >= 0; -- len_b) {
            add( (b[len_b] - '0') + carry, &sum, &carry );
            c[0] = sum + '0';
            s += string(c);            
        }

        if (carry == 1) {
            c[0] = '1';
            s += string(c);
        }
        
        reverse(s.begin(), s.end());        
        return s;
    }
    
    void add(int val, int *sum, int *carry) {
        if (val == 3) {
            *sum = 1;
            *carry = 1;
        } else if (val == 2) {
            *sum = 0;
            *carry = 1;
        } else {
            *sum = val;
            *carry = 0;
        }
    }
};
*/

int main() {
    Solution s;
    string a = "0";
    string b = "1";
    string sum = s.addBinary(a, b);
    cout << "sum = " << sum << endl;
    return 0;
}
