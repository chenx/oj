// Works. Tested. Extended version, work for 1-9, but not 0.
class Solution3 {
public:
    int countDigitOne(int n) {
        if (n < 1) return 0;
        
        int k = 1; // k can be 1, 2, 3, ..., 9. Not work for 0.
        int high, low, cur, ct = 0;;
        long long m = 1; // avoid overflow when m *= 10.
        
        for (; m <= n; m *= 10) {
            high = (n/m)/10;
            cur = (n/m) % 10;
            low = n - (n/m) * m;
            
            if (cur < k) ct += high * m;
            else if (cur == k) ct += high * m + low + 1;
            else ct += (high + 1) * m;
        }
        
        return ct;
    }
};

// Works too. From BianChengZhiMei.
class Solution2 {
public:
    // modified from original code.
    int countDigitOne(int n) {
        long long ct = 0, low = 0, cur = 0, high = 0, m = 1;
        
        for (; m <= n; m *= 10) {
            low = n - (n/m) * m;
            cur = (n/m) % 10;
            high = (n/m) / 10;
            
            switch (cur) {
                case 0: ct += high * m; break;
                case 1: ct += high * m + low + 1; break;
                default: ct += (high + 1) * m; break;
            }
        }
        return ct;
    }
    
    // original code from BianChengZhiMei.
    int countDigitOne2(int n) {
        if (n<1) return 0;
        long long ct = 0, f = 1, low = 0, cur = 0, high = 0;
        
        while (n / f) {
            low = n - (n/f)*f;
            cur = (n/f) % 10;
            high = n / (f * 10);
            
            switch (cur) {
                case 0: 
                    ct += high * f;
                    break;
                case 1:
                    ct += high * f + low + 1;
                    break;
                default:
                    ct += (high + 1) * f;
                    break;
            }
            
            f *= 10;
        }
        return ct;
    }
};

// From: https://leetcode.com/discuss/61269/0ms-8-lines-c-solution
class Solution {
public:
    int countDigitOne(int n) {
        if(n<1)return 0;
        long ones=0;
        for(long m=1;m<=n;m*=10){
            long a=n/m;
            long b=n%m;
            ones += (a+8)/10*m+(a%10==1)*(b+1);
        }
        return ones;
    }
};

/**
Number of Digit One
Difficulty: Medium

Given an integer n, count the total number of digit 1 appearing in 
all non-negative integers less than or equal to n.

For example:
Given n = 13,
Return 6, because digit 1 occurred in the following numbers: 
1, 10, 11, 12, 13.

Hint:

    Beware of overflow.

 */
