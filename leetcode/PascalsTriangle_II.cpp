//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/22/2012
// @Last modified: 12/22/2012
//

/*
 * v[i] = v[i] + v[i-1] for i = v.size() - 1 to 1.
 */

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v;
        v.push_back(1);
        if (rowIndex == 0) return v;
        v.push_back(1);
        if (rowIndex == 1) return v;
        
        for (int i = 1; i < rowIndex; i++) {
            for (int j = v.size() - 1; j > 0; j --) {
                v[j] = v[j] + v[j-1];
            }
            v.push_back(1);
        }
        
        return v;
    }
};


// This works too.

class Solution2 {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v(rowIndex+1);
        for (int i = 0; i <= rowIndex; ++ i) v[i] = 1;
        
        for (int i = 1; i < rowIndex; ++ i) {
            for (int j = i; j > 0; -- j) {
                v[j] = v[j] + v[j-1];
            }
        }
        
        return v;
    }
};

// This works too.
class Solution3 {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v(rowIndex+1);
        
        for (int i = 0; i <= rowIndex; ++ i) v[i] = 1;
        
        for (int i = 1; i <= rowIndex; ++ i) { // can start from i=2.
            for (int j = i-1; j >= 1; -- j) {
                v[j] = v[j] + v[j-1];
            }
        }
        
        return v;
    }
};

// This works too.
class Solution4 {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v(rowIndex+1);
        
        v[0] = 1;
        if (rowIndex == 0) return v;

        for (int j = 1; j <= rowIndex; ++ j) {
            for (int i = j - 1; i >= 1; -- i) {
                v[i] += v[i-1];
            }

            v[j] = 1;
        }

        return v;
    }
};

// This works too. Seems most clean.
class Solution5 {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v(rowIndex + 1);
        
        v[0] = 1;
        for (int i = 1; i <= rowIndex; ++ i) {
            v[i] = 1;
            for (int j = i-1; j > 0; -- j) {
                v[j] += v[j-1];
            }
        }
        
        return v;
    }
}  

// This works too.
// Note the use of function fill() on vector.
// ex:
// row 0: 1
// row 1: 1 1
// row 2: 1 2 1   <== only need to start processing from this row.
// row 3: 1 3 3 1
class Solution6 {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1);
        fill(row.begin(), row.end(), 1);
        
        for (int i = 2; i <= rowIndex; ++ i) {
            for (int j = i - 1; j > 0; -- j) {
                row[j] = row[j] + row[j - 1];
            }
        } 
        
        return row;
    }
}; 

/*
Problem:

Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space? 
 */
