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
