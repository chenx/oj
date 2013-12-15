/*
 * Notes:
 * 1) instead of int array or biset<26>, use one integer ct to store count. This is fast.
 * 2) when a repeated char is found, rewind current pos to after the last occurrence of it.
 *    e.g., abcbde, at the 2nd b, rewind to c. Thus the longest substring length is 4 (cbde).
 */
#include <bitset>
#include <iostream>
using namespace std;

class Solution {
public:
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
