//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/17/2012
// @Last modified: 1/21/2013
//

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

// This works too. And is much simpler in code.
// 1/21/2013
class Solution2 {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> ans;
        map<string, vector<string> > m;

        string ana;
        for (int i = 0; i < strs.size(); ++ i) {
            ana = strs[i];
            sort(ana.begin(), ana.end());
            m[ana].push_back(strs[i]);
        }

        for (map<string, vector<string> >::iterator it = m.begin();
             it != m.end(); ++ it) {
            if ((*it).second.size() > 1) {
                for (int j = 0; j < (*it).second.size(); ++ j) {
                    ans.push_back((*it).second[j]);
                }
            }
        }

        return ans;
    }
};


class Sig {
    const static int LEN = 26;
public:
    int sig[LEN];
    int index;
    Sig(int _index) {
        index = _index;
        for (int i = 0; i < LEN; i ++) { sig[i] = 0; }
    }
    bool operator<(const Sig& t) const // Note: const needed!
    {
		for (int i = 0; i < LEN; i ++) {
    	    if (this->sig[i] != t.sig[i]) return this->sig[i] < t.sig[i];
		}
        return 0; // equal.
	}
    bool operator==(const Sig& t) const
    {
    	for (int i = 0; i < LEN; i ++) {
    	    if (this->sig[i] != t.sig[i]) return this->sig[i] == t.sig[i];
		}
        return 1; // equal.
	}
};

bool myfunction(const Sig & s1, const Sig & s2) {
	for (int i = 0; i < 26; i ++) {
	    if (s1.sig[i] != s2.sig[i]) return s1.sig[i] < s2.sig[i];
	}
    return 0; //s1.sig[0] < s2.sig[0]; // equal.
}


// if more than 1 group of anagrams exist, append together.
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> v;
        vector<Sig> vs;
        
        // get signature.
        for (int i = 0; i < strs.size(); i ++) {
            Sig g(i);
            
            string s = strs[i];
            for (int j = 0; j < s.size(); j ++) {
                g.sig[s[j] - 'a'] += 1;
            }
            vs.push_back(g);
        }
        
        // sort.
        sort(vs.begin(), vs.end());//, myfunction);
        
        // get anagrams.
        bool found = false;
        int index = 0;
            
        for (int i = 1; i < vs.size(); i ++) {
            if (vs[i] == vs[index]) {
                if (! found) {
                    v.push_back(strs[vs[index].index]);
                    found = true;
                }
                v.push_back(strs[vs[i].index]);
            } else {
                found = false;
                index = i;
            }
        }
        
        return v;
    }
};


int main() {
    return 0;
}


/**
Group Anagrams  
Difficulty: Medium

Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note:

    For the return value, each inner list's elements must follow the lexicographic order.
    All inputs will be in lower-case.

 */
