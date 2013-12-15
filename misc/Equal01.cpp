//
// Given a string of 1 and 0. 
// Find the longest substring with equal number of 1 and 0.
//
// @By: Xin Chen
// @Created on: 3/21/2013
// @Last modified: 3/21/2013
//
//
#include <map>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    // simple method: brute force.
    // return max length, L and R are start and end positions of the found string.
    // if not found, return 0.
    // O(1) space, O(n^2) time.
    int getSame01Str(string s, int &L, int &R) {
        if (s.length() == 0) return 0;
        
        int ct1 = 0, ct0 = 0, maxlen = 0, len, left;
        for (int i = 0; i < s.length(); ++ i) {
            ct0 = ct1 = 0;
            len = 0;
            left = i;
            for (int j = i; j < s.length(); ++ j) {
                if (s[j] == '0') ++ ct0;
                else ++ ct1;
                
                ++ len;
                if (ct0 == ct1 && len > maxlen) {
                    maxlen = len;
                    L = left;
                    R = j;
                }
            }
        }
        
        return maxlen;
    }
    
    // O(n) space, O(n) time.
    // 
    // use a sumleft[] array, sumleft[i] is sum from s[0] to s[i], use value -1 for '0', 1 for '1'.
    // the answer can be for a string that:
    // 1) starts from 0: use the right most i where sumleft[i] == 0.
    // 2) starts from middle of s: find the pair (sumleft[i], sumleft[j]) that maximizes j-i.
    //    use a hash table to store value of sumleft[i], if a value already exists, check length j-i.
    //
    // The idea is from: http://www.geeksforgeeks.org/largest-subarray-with-equal-number-of-0s-and-1s/
    //
    // Note: you don't need to record both L and R, just L and returned length are enough
    //
    int getSame01Str_2(string s, int &L) {
        if (s.length() == 0) return 0;
        
        map<int, int> hash;
        int len, maxlen = 0, left;
        int n = s.length();
        int sumleft[n];
        int sum = 0;
        
        for (int i = 0; i < n; ++ i) {
            sum += (s[i] == '0') ? -1 : 1;
            if (sum == 0 && i+1 > maxlen) {
                maxlen = i+1;
                L = 0; // R = i;
            }
            else {
                if (hash.find(sum) != hash.end()) {
                    if (i - hash[sum] > maxlen) {
                        maxlen = i - hash[sum];
                        L = i - maxlen + 1; // R = i;
                    }
                }
                else {
                    hash[sum] = i;
                }
            }
        }
        
        return maxlen;
    }
};

void test(string s) {
    Solution so;
    
    cout << "--1--" << endl;
    int L = 0, R = 0;
    int maxlen = so.getSame01Str(s, L, R);
    if (maxlen > 0) {
        cout << s << ": " << maxlen << " (" << s.substr(L, R - L + 1) << ")" << endl;
    } 
    else {
        cout << s << ": not found" << endl;
    }
    
    cout << "--2--" << endl;
    int L2 = 0, R2 = 0;
    int maxlen2 = so.getSame01Str_2(s, L2);
    if (maxlen2 > 0) {
        cout << s << ": " << maxlen2 << " (" << s.substr(L2, maxlen2) << ")" << endl;
    } 
    else {
        cout << s << ": not found" << endl;
    }
}

int main() {
    test("");
    test("0");
    test("1");
    test("111111111");
    test("10");
    test("100");
    test("1001");
    test("100101001");
    test("0001010010000");
    return 0;
}
