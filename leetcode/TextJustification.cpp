//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 1/1/2013
// @Last modified: 1/2/2013
//
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> vs;
        int len = words.size();
        if (len == 0) return vs;
        
        string s;
        int space_ct, len_sum = 0, start, end;
        for (int i = 0; i < len; i ++) { // assume each word len < L.
            //if (words[i].length() > L) break; //
            
            if (len_sum == 0) {
                len_sum = words[i].length();
                start = i;
            }
            else {
                len_sum += 1 + words[i].length();
                if (len_sum >= L) {
                    if (len_sum > L) {
                        len_sum -= 1 + words[i].length();                        
                        -- i; // Can't move this above the above statement.
                    }
                    end = i;
                    space_ct = (end - start) + L - len_sum;
                    s = output(words, start, end, space_ct, L);
                    vs.push_back( s );
                    len_sum = 0;
                }
            }
        } // end of for
        
        if (len_sum >= 0) { // last words. Note: need to use ">=" here! to cover case of empty string.
            end = len - 1;
            space_ct = (end - start);
            s = output(words, start, end, space_ct, L);
            vs.push_back( s );
        }
        
        return vs;
    }
    
    // Note: Need to fill the end with padding of spaces.
    string output(vector<string> & words, 
                  int start, int end, int space_ct, int L) {
        if (start == end) {
            string s = words[start];
            int len = s.length();
            for (int i = 0; i < L - len; i ++) s += " "; // padding
            return s;
        }
        int q = space_ct / (end - start); // quotient.
        int r = space_ct % (end - start); // remainder.
        string s = "";
        
        // First r intervals each has q+1 spaces,
        // rest intervals each has q spaces.
        int i;
        for (i = start; i < end; ++ i) {
            s += words[i];
            for (int j = 0; j < q; ++ j) s += " ";
            if (r > 0) {
                s += " ";
                -- r;
            }
        }
        s += words[i]; // last word. 
        int len = s.length();
        for (i = 0; i < L - len; i ++) s += " "; // padding last word.
        
        return s;
    }
};

int main() {
    
    return 0;
}
