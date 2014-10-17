/*
 * Notes:
 * 1) instead of int array or biset<26>, use one integer ct to store count. This is fast.
 * 2) when a repeated char is found, rewind current pos to after the last occurrence of it.
 *    e.g., abcbde, at the 2nd b, rewind to c. Thus the longest substring length is 4 (cbde).
 */
#include <bitset>
#include <iostream>
using namespace std;


// New code, 9/22/2014
// Updated from the previous code, since the question changed alphabet from
// lower case a-z to the entire ascii set. So the change here is mostly
// change from an integer ct to an array ct[256]. It could use bitset<256> ct,
// but bitset is not supported in leetcode.
class Solution {
public:
    // This works too!
    int lengthOfLongestSubstring4(string s) {
        if (s == "") return 0;
        int ct[256];
        int pos[256]; // keep last occurrence pos of each letter.
        memset(ct, 0, sizeof(int) * 256);
        
        int len = 0, max_len = 0, index, n = s.length();
        for (int i = 0; i < n; i ++) {
            index = s[i]; 
            if (ct[index] == 0) {
                ct[index] = 1;
                pos[index] = i;
                len ++;
                if (len > max_len) max_len = len;
            } 
            else {
                i = pos[index]; // rewind to cover overlap. Note after this i ++.
                len = 0;
                memset(ct, 0, sizeof(int) * 256);
            }
        }
        
        return max_len;
    }
    
    // This works!
    int lengthOfLongestSubstring(string s) {
        int pos[256];
        int exist[256];
        memset(pos, 0, sizeof(int) * 256);
        memset(exist, 0, sizeof(int) * 256);
        int max_len = 0, len = 0;
        
        int i = 0, n = s.length();
        while (i < n) {
            int v = s[i]; 
            if ( exist[v] ) {
                len = 0;
                i = pos[v] + 1;
                memset(exist, 0, sizeof(int) * 256);
            }
            else {
                exist[v] = 1;
                pos[v] = i;
                ++ len;
                ++ i;
                if (len > max_len) max_len = len;
            }
        }
        
        return max_len;
    }
    
    // This does NOT work.   
    int lengthOfLongestSubstring2(string s) {
        int pos[26];
        int exist = 0, max_len = 0, len = 0;
        
        int i = 0, n = s.length();
        while (i < n) {
            char c = s[i];
            int v = c - 'a';
            if ( (exist >> v) & 1 ) {
                max_len = len;
                len = 1; // i - pos[v];
                i = pos[v] + 1;
                exist = 1 << v;
            }
            else {
                exist |= (1 << v);
                pos[v] = i;
                ++ len;
                ++ i;
            }
        }
        
        return max_len;
    }
};


// Old code in 2013.
class Solution_old {
public:
    // This works.
    int lengthOfLongestSubstring(string s) {
        if (s == "") return 0;
        int ct = 0;  // use this instead of bitset<26> for efficiency and ease.
        int pos[26]; // keep last occurrence pos of each letter.
        
        int len = 0, max_len = 0, index;
        for (int i = 0; i < s.length(); i ++) {
            index = s[i] - 'a';
            if ((ct & (1 << index)) == 0) {
                ct |= (1 << index);
                pos[index] = i;
                len ++;
                if (len > max_len) max_len = len;
            } 
            else {
                i = pos[index]; // rewind to cover overlap. Note after this i ++.
                len = 0;
                ct = 0;
            }
        }
        
        return max_len;
    }
           
    // this does not work, because it does not consider overlap.
    int lengthOfLongestSubstring_wrong(string s) {
        if (s == "") return 0;
        bitset<26> ct;
        int i;
        ct.reset();
        cout << "ct: " << ct << endl;
                        
        int len = 0, max_len = 0, index;
        for (i = 0; i < s.length(); i ++) {
            index = s[i] - 'a';
            if (ct[index] == 0) {
                ct.set(index);
                len ++;
                if (len > max_len) max_len = len;
            } 
            else {
                ct.reset();
                ct.set(index);
                len = 1;
            }
        }
        
        return max_len;
    }
};

int main() {
    Solution o;
    string s = "abcbde";
    cout << o.lengthOfLongestSubstring(s) << endl;
    return 0;
}
