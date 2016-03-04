//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 1/9/2013
// @Last modified: 1/9/2013
//

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > vs;
        
        // can't use = {0} to initalized since num.size() is not constant.
        // int t[10] = {0} is allowed though.
        int s[num.size()]; 
        //int * s = new int[num.size()];
        for (int i = 0; i < num.size(); i ++) s[i] = 0;
        permutation(vs, num, s, 0, num.size());
        //delete[] s;
        
        return vs;
    }
    
    // Note: s should be initialized to all 0s.
    // permutation2() is optimized more.
    void permutation(
        vector<vector<int> > &vs, vector<int> &num,
        int s[], int pos, int len) {
      if (pos == len) { output(vs, num, s); }
    
      for (int i = 0; i < len; i ++) {
        if(s[i] == 0) {
          s[i] = pos + 1; 
          permutation(vs, num, s, pos + 1, len); 
          s[i] = 0;
        }
      }
    }
    
    // This works and is more efficient than permutation()
    // since it avoids one more unnecessary function call.
    void permutation2(
        vector<vector<int> > &vs, vector<int> &num,
        int s[], int pos, int len) {
    
      for (int i = 0; i < len; i ++) {
        if(s[i] == 0) {
          s[i] = pos + 1; 
    
          if (s[i] == len) { output(vs, num, s); }
          else { permutation(vs, num, s, s[i], len); }
    
          s[i] = 0;
        }
      }
    }
    
    // Note: s[j] is 1-based, so should use s[j] - 1 here.
    void output(vector<vector<int> > &vs, vector<int> &num, int s[]) {
        vector<int> v(num.size());
        for (int j = 0; j < num.size(); j ++) v[j] = num[s[j] - 1]; // NOTE: s[j] - 1, not s[j]!!!
        vs.push_back(v);        
    }

};

// Another solution is the same as Permutation II.
class Solution2 {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > v;
        sort(num.begin(), num.end());
        do { v.push_back(num); } while (nextPerm(num));
        return v;
    }
    
    bool nextPerm(vector<int> &num) {
        int len = num.size();
        if (len <= 1) return false;
        
        int i, j;
        
        // from tail to head, find the first element e[i], s.t., e[i] < e[i+1].
        for (i = len - 2; i >= 0 && num[i] >= num[i+1]; -- i) ; // NOTE: start with i = len - 2.
        
        if (i < 0) { // num in DESC order already.
            reverse(num.begin(), num.end()); // go to first permutation.
            return false;
        }
        
        // swap e[i] with the minimal rhs number e[j], where e[i] < e[j].
        for (j = len - 1; num[j] <= num[i]; -- j) ;
        swap (num[i], num[j]);
        
        // sort the rhs of e[i] in DESC order.
        reverse(num.begin() + i + 1, num.end());
        
        return true;
    }
};

// This works. Iterative version.
// From: https://leetcode.com/discuss/59888/my-concise-c-solution-without-using-recursion
class Solution3 {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result(1);
        for(int i = 0, n = nums.size(); i < n; ++ i){
            int size = result.size();
            int m = result[0].size();
            for(int j = 0; j < size; ++ j){
                result[j].push_back(nums[i]);
                for(int k = 0; k < m; ++ k){
                    vector<int> v = result[j];
                    swap(v[k], v[m]);
                    result.push_back(v);
                }
            }     
        }
        return result;
    }
};

// Works too. Iterative. By: XC. 2/24/2016
// Idea:
// say for n numbers, the permutations are p1, p2, ...
// then for n+1 numbers, answer is for each of pi, insert (n+1)-th number
// at each position of pi and add it to result.
class Solution4 {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return vector<vector<int>>();

        // Generate permutations of (1, 2, ..., n-1).
        vector<vector<vector<int>>> ans(n);
        vector<vector<int>> v0(1, vector<int>(1, 0));
        ans[0] = v0;
        
        for (int i = 1; i < n; ++ i) {
            for (int j = 0, lenj = ans[i-1].size(); j < lenj; ++ j) {
                vector<int> &v = ans[i-1][j];
                for (int m = 0; m <= v.size(); ++ m) {
                    ans[i].push_back(v);
                    ans[i].back().insert(ans[i].back().begin() + m, i);
                }
            }
        }
        
        // replace index with actual value in nums.
        for (int i = 0; i < ans[n-1].size(); ++ i) {
            for (int j = 0; j < ans[n-1][i].size(); ++ j) {
                ans[n-1][i][j] = nums[ans[n-1][i][j]];
            }
        }

        return ans[n-1];
    }
};

// Works too. Modified from Solution 4.
// The 2 changes are labled in code below.
class Solution5 {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return vector<vector<int>>();

        vector<vector<vector<int>>> ans(n);
        vector<vector<int>> v0(1, vector<int>(1, nums[0])); // change 1.
        ans[0] = v0;
        
        for (int i = 1; i < n; ++ i) {
            for (int j = 0, lenj = ans[i-1].size(); j < lenj; ++ j) {
                vector<int> &v = ans[i-1][j];
                for (int m = 0; m <= v.size(); ++ m) {
                    ans[i].push_back(v);
                    ans[i].back().insert(ans[i].back().begin() + m, nums[i]); // change 2.
                }
            }
        }

        return ans[n-1];
    }
};


// Works too. Tested.
// v is passed by reference, so in final step, must use a new vector u.
// Otherwise will have runtime error.
class Solution6 {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        if (n == 0) return ans;
        
        vector<int> v(n, 0); // int v[n] = {0}; // works too.
        perm(nums, ans, v, 0);
        return ans;
    }
    
    void perm(vector<int> &nums, vector<vector<int>> &ans, vector<int> &v, int pos) {
        int n = nums.size();
        if (pos == n) {
            vector<int> u(n);
            for (int i = 0; i < n; ++ i) {
                u[i] = nums[v[i] - 1];
            }
            ans.push_back(u);
            return;
        }
        
        for (int i = 0; i < n; ++ i) {
            if (v[i] == 0) {
                v[i] = pos + 1;
                perm(nums, ans, v, pos + 1);
                v[i] = 0;
            }
        }
    }
};

/**
Permutations
Difficulty: Medium

Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1]. 
 */
