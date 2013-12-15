//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/22/2012
// @Last modified: 12/22/2012
//

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > vs;
        if (numRows == 0) return vs;

        vector<int> v;
        v.push_back(1);
        vs.push_back(v);
        
        for (int i = 1; i < numRows; i ++) {
            vector<int> v;
            v.push_back(1);
            for (int j = 0; j < i - 1; j ++) {
                v.push_back(vs[i-1][j] + vs[i-1][j+1]);
            }
            v.push_back(1);
            vs.push_back(v);
        }
        
        return vs;
    }
};


// This works too.
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int > > ans;
        
        for (int i = 0; i < numRows; ++ i) {
            vector<int> v(i+1);
            v[0] = 1;
            for (int j = 1; j < i; ++ j) {
                v[j] = ans[i-1][j-1] + ans[i-1][j];
            }
            v[i] = 1;
            ans.push_back(v);
        }
        
        return ans;
    }
};