//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 1/9/2013
// @Last modified: 1/20/2013
//

// This works.
// From: https://github.com/anson627/leetcode/blob/master/CombinationSum/CombinationSum.cpp
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > result;
        sort(candidates.begin(), candidates.end());
        if (candidates[0] > target) return result;
        
        vector<int> combination;
        combinationSumHelper(candidates, target, 0, combination, result);
        
        return result;
    };

    // Note: combination is passed as copy/value.
    void combinationSumHelper(vector<int> &candidates, int target, 
            int i, vector<int> combination, vector<vector<int> > &result) {
        if (target < 0) return;
        if (target == 0) {
                if (find(result.begin(), result.end(), combination) == result.end())
                    result.push_back(combination);
            return;
        }
        if (i == candidates.size()) return;
        for (int j = 0; j * candidates[i] <= target; j++) {
            if (j != 0) combination.push_back(candidates[i]);
            combinationSumHelper(candidates, target - j * candidates[i], i + 1, combination, result);
        }
    };
};


// This works too.
// From: http://blog.csdn.net/tingmei/article/details/8043966
class Solution2 {  
public:  
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {  
        vector< vector <vector<int> > > sum(target+1);  
        int nSize = candidates.size();  
        
        for (int i = 1; i <= target; ++i) {
            for (int j = 0; j < nSize; ++j) {
                if (i < candidates[j]) {
                    continue;  
                }
                else if (i == candidates[j]) {  
                    sum[i].push_back(vector<int>());  
                    sum[i].back().push_back(candidates[j]);  
                    continue;  
                } else {  
                    int tmp = i - candidates[j];  
                    for (int k = 0; k < sum[tmp].size(); ++k) {
                        if (sum[tmp][k].back() <= candidates[j]) {
                            sum[i].push_back(vector<int>(sum[tmp][k]));  
                            sum[i].back().push_back(candidates[j]);  
                        }  
                    }  
                }  // end of if-else
            }  // end of for.
        }  // end of for.
        return sum[target];  
    }  
};  


//
// This works too. I figured this out myself!
// Thomas Chen
//
class Solution3 {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<vector<int> > > ans;
        
        sort(candidates.begin(), candidates.end());
        for (int i = 0; i <= target; ++ i) {
            vector<vector<int> > row;
            for (int j = 0; j < candidates.size(); ++ j) {
                if (i < candidates[j]) break;
                if (i == candidates[j]) {
                    vector<int> v;
                    v.push_back(i);
                    row.push_back(v);
                    break;
                }
                vector<vector<int> > w = ans[i - candidates[j]]; // i is current target.
                if (w.size() > 0) {
                    for (int k = 0; k < w.size(); ++ k) {
                        w[k].push_back(candidates[j]);
                        // Note: you must sort here, because find() considers [1,2] and [2,1] different.
                        sort(w[k].begin(), w[k].end());
                        
                        if (find(row.begin(), row.end(), w[k]) == row.end()) {
                            row.push_back(w[k]);
                        }
                    }
                }
            }
            ans.push_back(row);
        }
        return ans[target];
    }
};


//
// This works too. Modified from Solution4.
// Here use "if (w[k].back() <= candidates[j])", to guarantee uniqueness of combination to insert,
// then no need to sort and search for existing copy like in Solution3.
// Thomas Chen
//
class Solution4 {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<vector<int> > > ans;
        
        sort(candidates.begin(), candidates.end());
        for (int i = 0; i <= target; ++ i) {
            vector<vector<int> > row;
            for (int j = 0; j < candidates.size(); ++ j) {
                if (i < candidates[j]) break;
                if (i == candidates[j]) {
                    vector<int> v;
                    v.push_back(i);
                    row.push_back(v);
                    break;
                }
                vector<vector<int> > w = ans[i - candidates[j]];
                if (w.size() > 0) {
                    for (int k = 0; k < w.size(); ++ k) {
                        if (w[k].back() <= candidates[j]) {
                            w[k].push_back(candidates[j]);
                            row.push_back(w[k]);
                        }
                    }
                }
            }
            ans.push_back(row);
        }
        return ans[target];
    }
};


//
// This works too. And this is just MORE clear.
//
class Solution5 {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<vector<int> > > ans(1+target);
        
        for (int i = 1; i <= target; ++ i) {
            for (int j = 0; j < candidates.size(); ++ j) {
                if (i == candidates[j]) {
                    vector<int> v(1);
                    v[0] = candidates[j];
                    ans[i].push_back(v);
                }
                else if (i > candidates[j]) {
                    vector<vector<int> > w = ans[i - candidates[j]];
                    for (int k = 0; k < w.size(); ++ k) {
                        vector<int> v = w[k];
                        v.push_back(candidates[j]);
                        sort(v.begin(), v.end());
                        if (find(ans[i].begin(), ans[i].end(), v) == ans[i].end()) {
                            ans[i].push_back(v);
                        }
                    }
                }
            } // end for
        } // end for
        
        return ans[target];
    }
};


// This works too and is very clean.
// 1) i can start from 1 instead of 0. 2) if use sort, then can break. See below.
// 3) use hash (&) on line 204, to save cost of creating new copy.
// 4) don't use hash on line 207, to create new copy of array.
class Solution6 {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<vector<int> > > ans(1+target);
        
        //sort(candidates.begin(), candidates.end());
        for (int i = 1; i <= target; ++ i) {
            for (int j = 0; j < candidates.size(); ++ j) {
                if (i == candidates[j]) {
                    vector<int> v(1);
                    v[0] = candidates[j];
                    ans[i].push_back(v);
                    //break; // if use sort above, then can use break here.
                }
                else if (i > candidates[j]) {
                    vector<vector<int> > &w = ans[i - candidates[j]];
                    for (int k = 0; k < w.size(); ++ k) {
                        if (candidates[j] >= w[k].back()) {
                            vector<int> v = w[k];
                            v.push_back(candidates[j]);
                            ans[i].push_back(v);
                        }
                    }
                }
            } // end for
        } // end for
        
        return ans[target];
    }
};
