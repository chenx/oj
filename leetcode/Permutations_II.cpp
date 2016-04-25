//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 1/9/2013
// @Last modified: 1/9/2013
//

// Iterative. Should work, but times out for large input. 
// Actually, times out for input as small as: [3,3,0,0,2,3,2]
// Works for lintcode though.
class Solution2 {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        if (n == 0) return ans;
        
        ans.push_back({nums[0]});
        
        for (int i = 1; i < n; ++ i) {
            vector<vector<int>> tmp;
            for (int j = 0, m = ans.size(); j < m; ++ j) {
                for (int k = 0; k <= ans[j].size(); ++ k) {
                    vector<int> t = ans[j];
                    if (k > 0 && nums[i] == *(t.begin() + k - 1)) continue; // cut branch. // ok without this.
                    t.insert(t.begin() + k, nums[i]);
                    if (find(tmp.begin(), tmp.end(), t) == tmp.end())
                        tmp.push_back(t);
                }
            }
            ans = tmp;
        }
        
        return ans;
    }
};

// The key is the use of nextPermutation() function!
// It can also use the built-in next_permuation function, which will be
// next_permuation(num.begin(), num.end()).
// Note: This also can be used for Permutation I solution.
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end() ) ;  
        vector<vector<int> > ret;
        do{
                ret.push_back( num );
        } while (nextPermutation(num));
        return ret;
    }   
    
    bool nextPermutation(vector<int> &num) {
        int n = num.size();
        if (n <= 1) return false;
        
        int i, j;
        for (i = n - 2; i >= 0 && num[i] >= num[i + 1]; -- i) ; 
        
        if (i < 0) { // last permutation already. Go to the first permutation.
            return false;
            //sort(num.begin(), num.end()); // or reverse(num.begin(), num.end());
        } 
        else {
            // get the minimal number x > num[pos] from rhs of x.
            // since the rhs of x is sorted DESC, the first x > num[pos] will do.
            // Note: '<=' is needed when duplicated elements exist, '<' not enough.
            for (j = n - 1; num[j] <= num[i]; -- j) ; 
            swap(num[i], num[j]);
            
            // sort rhs of pos in INC order.
            reverse(num.begin() + i + 1, num.end());     // or reverse.     
            return true;
        }
    }
};

// Another method: http://blog.csdn.net/tingmei/article/details/8048341
// But I don't understand it so far.
