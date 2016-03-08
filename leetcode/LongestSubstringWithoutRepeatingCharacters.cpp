/*
 * Notes:
 * 1) instead of int array or biset<26>, use one integer ct to store count. This is fast.
 * 2) when a repeated char is found, rewind current pos to after the last occurrence of it.
 *    e.g., abcbde, at the 2nd b, rewind to c. Thus the longest substring length is 4 (cbde).
 */
#include <bitset>
#include <iostream>
using namespace std;

// This works too. Slightly better than Solution6.
class Solution7 {
public:
    int lengthOfLongestSubstring(string s) {
        const int SIZE = 256;
        int pos[SIZE] = {0};
        int len = 0, mlen = 0;
        
        for (int i = 0, n = s.length(); i < n; ++ i) {
            if (pos[s[i]] == 0) {
                pos[s[i]] = i + 1;
                ++ len;
            }
            else {
                mlen = max(len, mlen);
                len = 0;
                i = pos[s[i]] - 1;
                memset(pos, 0, SIZE * sizeof(int));
            }
        }
        mlen = max(len, mlen); // need this since now get mlen only when pos[s[i]] != 0.
         
        return mlen;
    } 
};

// This works too. Maybe be best answer so far.
// Removed array ct[] from previous solutions, which is redundant from pos[].
// use pos[c] == 0 to denote not-exist.
// Better than previous solutions. 1-24-2015.
class Solution6 {
public:
    int lengthOfLongestSubstring(string s) {
        const int SIZE = 256;
        int pos[SIZE] = {0}; 
        //int pos[SIZE];
        //memset(pos, 0, sizeof(int) * SIZE);
        int maxLen = 0, len = 0, n = s.length();
        
        for (int i = 0; i < n; ++ i) {
            if (pos[s[i]] == 0) {
                pos[s[i]] = i + 1;
                ++ len;
                maxLen = max(maxLen, len);
            }
            else {
                len = 0;
                i = pos[s[i]] - 1;
                memset(pos, 0, sizeof(int) * SIZE);
            }
        }
        
        return maxLen;
    }
}

// This works too. 
// Note update value of maxlen either at the 2 places as below, or at single place of commented-out.
// 11/7/2014
class Solution5 {
public:
    int lengthOfLongestSubstring(string s) {
       const int SIZE = 256;
       int pos[SIZE];
       int ct[SIZE];
       int len = 0, maxlen = 0;
       memset(ct, 0, SIZE * sizeof(int));
       
       for (int i = 0; i < s.length(); ++ i) {
           if (ct[s[i]] == 0) {
               ct[s[i]] = 1;
               pos[s[i]] = i;
               ++ len;
               // maxlen = max(maxlen, len); // 1) update method 1.
           }
           else {
               maxlen = max(maxlen, len); // 2) update method 2.
               i = pos[s[i]];
               len = 0;
               memset(ct, 0, SIZE * sizeof(int));
           }
       }
       
       maxlen = max(maxlen, len); // 2) update method 2.
       return maxlen; 
    }
};

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
