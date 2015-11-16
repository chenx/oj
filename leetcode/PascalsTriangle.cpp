//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/22/2012
// @Last modified: 12/22/2012
//

// This works too.
class Solution4 {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> list;
        if (numRows == 0) return list;

        vector<int> ls;
        ls.push_back(1);
        list.push_back(ls);
        
        for (int i = 1; i < numRows; ++ i) {
            vector<int> ls;
            ls.push_back(1);
            vector<int> &ls0 = list[i-1];
            for (int j = 1; j < i; ++ j) { // be careful of boundary: j < i
                ls.push_back(ls0[j-1] + ls0[j]);
            }
            ls.push_back(1);
            list.push_back(ls);
        }
        
        return list;        
    }
};

// This works too.
class Solution3 {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > rows;
        if (numRows == 0) return rows;

        vector<int> row1(1);
        row1[0] = 1;
        rows.push_back(row1);
        
        for (int i = 1; i < numRows; ++ i) {
            vector<int> v = rows[i - 1]; // copy the previous row.
            v.push_back(1);              // add last 1.
            for (int j = i-1; j > 0; -- j) v[j] += v[j - 1]; // update elements.
            
            rows.push_back(v);           // add new row.
        }
        
        return rows;
    }
};

// This works too.
class Solution2 {
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
