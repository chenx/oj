## Next permutation

class Solution {
public:
   void nextPermutation(vector<int>& nums) {
       int n = nums.size();


       int i, j;
       // Find first i, nums[i] < nums[i+1]
       for (i = n-2; i >= 0 && nums[i] >= nums[i+1]; i --) ;
       if (i == -1) {
           reverse(nums.begin(), nums.end());
           return;
       }


       // Find first item from right, nums[j] > nums[i]
       for (j = n-1; nums[j] <= nums[i]; --j) ;
       swap(nums[i], nums[j]);
       reverse(nums.begin() + i + 1, nums.end());
   }
};


## Permutations

// Iterative. DP.
class Solution {
public:
   vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>> ans;
       int n = nums.size();
       if (n == 0) return ans;


       ans.push_back(vector<int>(1, nums[0]));
       for (int i = 1; i < n; i ++) {
           vector<vector<int>> v;
           for (int j = 0; j < ans.size(); ++ j) {
               vector<int>& u = ans[j];
               for (int k = 0; k <= u.size(); k ++) {
                   v.push_back(u);
                   v.back().insert(v.back().begin() + k, nums[i]);
               }
           }
           ans = v;
       }
       return ans;
   }
};


// Iterative.
class Solution2 {
public:
   vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>> ans;
       sort(nums.begin(), nums.end());
       do { ans.push_back(nums); } while (nextPerm(nums));
       return ans;
   }

   bool nextPerm(vector<int>& nums) {
       int n = nums.size();
       if (n <= 1) return false;

       int i, j;
       for (i = n - 2; i >= 0 && nums[i] >= nums[i+1]; i --) ;

       if (i == -1) {
           reverse(nums.begin(), nums.end());
           return false;
       }

       for (j = n - 1; nums[j] <= nums[i]; j --) ;
       swap(nums[i], nums[j]);

       reverse(nums.begin() + i + 1, nums.end());
       return true;
   }
};


// Recursive
class Solution3 {
public:
   vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>> ans;
       int n = nums.size();
       if (n == 0) return ans;

       vector<int> s(n, 0);
       permutation(ans, nums, s, 0, n);
       return ans;
   }

   void permutation(vector<vector<int>>& ans, vector<int>& nums, vector<int> s, int pos, int n) {
       if (n == pos) {
           vector<int> v(n, 0);
           for (int i = 0; i < n; i ++) v[i] = nums[s[i] - 1];
           ans.push_back(v);
           return;
       }

       for (int i = 0; i < n; i ++) {
           if (s[i] == 0) {
               s[i] = pos + 1;
               permutation(ans, nums, s, pos + 1, n);
               s[i] = 0;
           }
       }
   }
}
