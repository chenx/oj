//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/18/2012
// @Last modified: 12/18/2012
//

// This works too. Use O(n) space. This does not destroy triangle. 11/4/2014.
class Solution2 {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int n = triangle.size();
        if (n == 0) return 0;
        vector<int> v = triangle[n-1];
        
        for (int i = n-2; i >= 0; -- i) {
            for (int j = 0; j <= i; ++ j) {
                v[j] = triangle[i][j] + min(v[j], v[j+1]);
            }
        }
        
        return v[0];
    }
};

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
       //return sum(triangle, 0, 0);
       return sum2(triangle);
    }

    // in place. Better !
    // To find the path using O(triangle.size()) space, 
    // go top-down, each time use the min side. 
    // Note the path may not be unique.
    // This is bottom-up DP.
    int sum2(vector<vector<int> > &t) {
        int i, j, len = t.size() - 1;
        for (i = len - 1; i >= 0; -- i) {
            for (j = 0; j <= i; ++ j) {
                t[i][j] = t[i][j] + min(t[i+1][j], t[i+1][j+1]);
            }
        }
        return t[0][0];
    }

    // recursive, will time out for large test set.
    // T[level][i] = Triangle[level][i] + min(Triangle[level+1][i], Triangle[level+1][i+1]);
    int sum(vector<vector<int> > &triangle, int level, int i) {
         if (level == triangle.size() - 1) {
             return triangle[level][i];
         }
            
         return triangle[level][i] + 
                min(sum(triangle, level + 1, i), 
                    sum(triangle, level + 1, i + 1));
    }

};

/*
Problem:

Given a triangle, find the minimum path sum from top to bottom. 
Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]

The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, 
where n is the total number of rows in the triangle. 
 */
