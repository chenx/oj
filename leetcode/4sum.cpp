//
// http://www.leetcode.com/onlinejudge#
// 3sum.
// @Author: Xin Chen
// @Created on: 12/13/2012
// @Last modified: 12/13/2012
//

// Works. Shorter and cleaner than previous solutions.
class Solution5 {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        if (n <= 3) return ans;

        sort(nums.begin(), nums.end());
        
        for (int L = 0; L < n - 3; ++ L) {
            if (L > 0 && nums[L] == nums[L - 1]) continue;
            
            vector<vector<int>> v = threeSum(nums, L + 1, target - nums[L]);
            for (int i = 0; i < v.size(); ++ i) {
                ans.push_back(v[i]);
                ans.back().insert(ans.back().begin(), nums[L]);
            }
        }
        
        return ans;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums, int L, int target) {
        vector<vector<int>> ans;
        int n = nums.size(), L0 = L;

        for (; L < n - 2; ++ L) {
            if (L > L0 && nums[L-1] == nums[L]) continue;
            
            for (int M = L + 1, R = n - 1; M < R; ) {
                int sum = nums[L] + nums[M] + nums[R];
                if (sum == target) 
                    ans.push_back({nums[L], nums[M], nums[R]});

                if (sum <= target) 
                    while (M < R && nums[M] == nums[++ M]) ;
                else 
                    while (M < R && nums[R] == nums[-- R]) ;
            }
        }
        
        return ans;
    }
};

// This works too. Avoid search to find duplicates.
class Solution4 {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        
        int len = nums.size();
        for (int L = 0; L < len - 3; ++ L) {
            if (L > 0 && nums[L] == nums[L - 1]) continue;
            
            vector<vector<int>> v3 = threeSum(nums, L + 1, target - nums[L]); // <- L + 1.
            for (int i = 0; i < v3.size(); ++ i) {
                ans.push_back(getV4(nums[L], v3[i][0], v3[i][1], v3[i][2])); 

                // this works too.
                //v3[i].insert(v3[i].begin(), nums[L]);
                //ans.push_back(v3[i]);

                // this works too.
                //ans.push_back(v3[i]);
                //ans.back().insert(ans.back().begin(), nums[L]);
            }
        }
        
        return ans;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums, int L, int target) {
        vector<vector<int>> ans;
        int R, M, len = nums.size(), L0 = L; // L0
        
        sort(nums.begin(), nums.end());
        for (; L < len - 2; ++ L) {
            if (L > L0 && nums[L] == nums[L - 1]) continue; // L > L0
            
            for (M = L + 1, R = len - 1; M < R; ) {
                int sum = nums[L] + nums[M] + nums[R];
                    
                if (sum == target) {
                    ans.push_back( getV(nums[L], nums[M], nums[R]) );
                    while (nums[M] == nums[++ M] && M < R) ;
                    while (nums[R] == nums[-- R] && M < R) ;
                }
                else if (sum < target) {
                    while (nums[M] == nums[++ M] && M < R) ;
                }
                else {
                    while (nums[R] == nums[-- R] && M < R) ;
                }
            }
        }
        
        return ans;
    }
    
    vector<int> getV(int a, int b, int c) {
        vector<int> v(3);
        v[0] = a; 
        v[1] = b; 
        v[2] = c;
        return v;
    }    

    vector<int> getV4(int a, int b, int c, int d) {
        vector<int> v(4);
        v[0] = a; 
        v[1] = b; 
        v[2] = c;
        v[3] = d;
        return v;
    }        
};


// This works too, and is the most clean.
class Solution3 {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > ans;
        if (num.size() < 4) return ans; // need this to avoid runtime error when num is empty.
        
        sort(num.begin(), num.end());
        for (int L = 0; L < num.size() - 3; ++ L) {
            vector<vector<int> > v = threeSum(num, L+1, target - num[L]);
            for (int i = 0; i < v.size(); ++ i) {
                vector<int> u(4);
                u[0] = num[L]; u[1] = v[i][0]; u[2] = v[i][1]; u[3] = v[i][2];
                if (find(ans.begin(), ans.end(), u) == ans.end()) {
                    ans.push_back(u);
                }
            }
        }
        return ans;
    }
    
    vector<vector<int> > threeSum(vector<int> &num, int L, int target) {
        vector<vector<int> > ans;
        for (; L < num.size() - 2; ++ L) {
            for (int M = L + 1, R = num.size() - 1; M < R; ) {
                int sum = num[L] + num[M] + num[R];
                if (sum == target) {
                    vector<int> v(3);
                    v[0] = num[L]; v[1] = num[M], v[2] = num[R];
                    if (find(ans.begin(), ans.end(), v) == ans.end()) {
                        ans.push_back(v);
                    }
                    ++ M;
                }
                else if (sum < target) ++ M;
                else -- R;
            }
        }
        return ans;
    }
};


// This one works. This uses the new threeSum function, and don't use the hash.
class Solution2 {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > ans;
        int len = num.size();
        if (len < 4) return ans;
        
        sort(num.begin(), num.end());
        
        for (int i = 0; i < len - 3; ++ i) { // first num: num[i].
            vector<vector<int> > sum3 = threeSum(num, i+1, target - num[i]);
            for (int j = 0; j < sum3.size(); ++ j) {
                vector<int> v(4);
                v[0] = num[i];
                v[1] = sum3[j][0];
                v[2] = sum3[j][1];
                v[3] = sum3[j][2];
                if (find(ans.begin(), ans.end(), v) == ans.end()) {
                    ans.push_back(v);
                }
            }
        }
        return ans;
    }
    
    vector<vector<int> > threeSum(vector<int> &num, int left, int target) {
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        int len = num.size();
        int sum;
        
        for (int L = left; L < len - 2; L ++) {
            // search [L+1, len - 1] for 2 numbers whose sum = -num[L].
            for (int M = L + 1, R = len - 1; M < R; ) {
                sum = num[M] + num[R] + num[L] - target;
                if (sum == 0) {
                    vector<int> x = getV(num[L], num[M], num[R]);
                    if (find(result.begin(), result.end(), x) == result.end()) {
                        result.push_back(x);
                    }
                    
                    M ++; // R -- also gets it all right.
                } else if (sum < 0) {
                    M ++;
                } else {
                    R --;
                }
            }
        }
        return result;
    }  
    
    
    vector<int> getV(int a, int b, int c) {
        vector<int> v;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        return v;
    }
};



struct compStr
{
    bool operator()(const char* a, const char* b) const
    {
         return strcmp(a, b) < 0;
    }
};

class Solution {
public:
    // O(n^3).
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        vector<vector<int> > sum3;
        set<char *, compStr> hash;
        char hash_val[50];
        sort(num.begin(), num.end());
        
        int i, len = num.size(), len3;
        for (i = 0; i < len - 3; i ++) {
            sum3 = threeSum(num, i + 1, num[i], target);
            if ((len3 = sum3.size()) > 0) {
                for (int j = 0; j < len3; j ++) {
                    vector<int> v(4);
                    v[0] = num[i], v[1] = sum3[j][0], v[2] = sum3[j][1], v[3] = sum3[j][2];
                    
                    sprintf(hash_val, "%d_%d_%d_%d", v[0], v[1], v[2], v[3]);
                    if (hash.find(hash_val) == hash.end()) {
                        hash.insert(strdup(hash_val));
                        result.push_back(v);
                    }
                }
            }
        }
        return result;
    }
    
    
    vector<vector<int> > threeSum(vector<int> &num, int left, int v1, int target) {
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        int len = num.size();
        int sum;
        set<char *, compStr> hash;
        char hash_val[40];
        
        for (int L = left; L < len - 2; L ++) {
            // search [L+1, len - 1] for 2 numbers whose sum = -num[L].
            for (int M = L + 1, R = len - 1; M < R; ) {
                sum = num[M] + num[R] + num[L] + v1;
                if (sum == target) {
                    sprintf(hash_val, "%d_%d_%d", num[L], num[M], num[R]);
                    if (hash.find(hash_val) == hash.end()) { 
                        hash.insert(strdup(hash_val));
                        
                        vector<int> v(3);
                        v[0] = num[L], v[1] = num[M], v[2] = num[R];
                        result.push_back(v);
                    }
                    
                    M ++; // R -- also gets it all right.
                } else if (sum < target) {
                    M ++;
                } else {
                    R --;
                }
            }
        }
        return result;
    }  
    
};


/**
4Sum
Difficulty: Medium

Given an array S of n integers, are there elements a, b, c, and d in S 
such that a + b + c + d = target? Find all unique quadruplets in the 
array which gives the sum of target.

Note:

    Elements in a quadruplet (a,b,c,d) must be in non-descending order. 
    (ie, a ≤ b ≤ c ≤ d)
    The solution set must not contain duplicate quadruplets.

    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)

 */
