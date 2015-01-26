//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 1/1/2013
// @Last modified: 1/2/2013
//
#include <iostream>
using namespace std;

// This works too! Only 20 lines.
// From: https://oj.leetcode.com/discuss/13610/share-my-concise-c-solution-less-than-20-lines
class Solution4 {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> res;
        for(int i = 0, k, l; i < words.size(); i += k) {
            for (k = l = 0; i + k < words.size() && l + words[i+k].size() <= L - k; k++) {
                l += words[i+k].size();
            }
            string tmp = words[i];
            for (int j = 0; j < k - 1; j++) {
                if(i + k >= words.size()) tmp += " ";
                else tmp += string((L - l) / (k - 1) + (j < (L - l) % (k - 1)), ' ');
                tmp += words[i+j+1];
            }
            tmp += string(L - tmp.size(), ' ');
            res.push_back(tmp);
        }
        return res;
    }
};

// This works too.
// From: https://oj.leetcode.com/discuss/19485/share-my-concise-solution-this-easy-should-classify-be-hard
class Solution3 {
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> ans, vs;
        string str;
        int len = 0, div = 0, mod = 0;

        for (int i = 0; i < words.size(); ++i) {
            if (len + vs.size() + words[i].size() <= L) {
                vs.push_back(words[i]);
                len += words[i].size();
            }
            else {
                if (vs.size() == 1) {
                    str = vs[0];
                    str.append(L - str.size(), ' ');
                    ans.push_back(str);
                }
                else if (vs.size() > 1) {
                    div = (L - len) / (vs.size() - 1);
                    mod = (L - len) % (vs.size() - 1);
                    str = vs[0];
                    for (int j = 1; j < vs.size(); ++j) {
                        if (j <= mod) str.append(div+1, ' '); // one more space
                        else str.append(div, ' ');
                        str += vs[j];
                    }
                    ans.push_back(str);
                }

                vs.clear();
                vs.push_back(words[i]);
                len = words[i].size();
            }
        }

        // add the last line
        // left justified and no extra space is inserted between words
        str = vs[0];
        for (int i = 1; i < vs.size(); ++i) {
            str += ' ' + vs[i];
        }
        str.append(L-str.size(), ' ');
        ans.push_back(str);
        return ans;
    }
};

// This works. Passed all test cases.
// From: https://oj.leetcode.com/discuss/17421/share-my-c-solution-about-30-lines
class Solution2 {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> ret;
        int n = words.size();
        if(n == 0 || L == 0) { ret.push_back(""); return ret; }
        int i = 0;
        while(i < n) {
           vector<string> ws;  // words of current line
           int ws_len = 0;
           while((i < n && ws.size() == 0) ||
                 (i < n && ws_len + ws.size() - 1 + words[i].size() + 1 <= L)) {
                     ws.push_back(words[i]);
                     ws_len += words[i].size();
                     i++;
            }
    
            int space = L - ws_len;
            if(i == n || ws.size() == 1){ //special cases: last line / one word in a line
                for(int j = 0; j < ws.size() - 1 && space > 0; ++j, --space) ws[j] += " "; // bug: use "&&" !
                for( ; space > 0; --space) ws[ws.size()-1] += " ";
            }
            else{
                while(space > 0){
                    for(int j = 0; j < ws.size() - 1 && space > 0; ++j, --space) ws[j] += " ";
                }
            }
    
            string str;
            for(string tmp : ws) str += tmp;
            ret.push_back(str);
        }
        return ret;
    }
};

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
