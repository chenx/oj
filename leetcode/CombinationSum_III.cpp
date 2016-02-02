// This works. 
// Based on the solution to CombinationSum.
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> candidates(9);
        for (int i = 1; i <= 9; ++ i) candidates.push_back(i);
        
        vector<vector<vector<int> > > ans(1 + n);
        
        //sort(candidates.begin(), candidates.end()); // 1) no need to sort.
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < candidates.size(); ++ j) {
                if (i < candidates[j]) {
                    break;  
                }
                else if (i == candidates[j]) {  
                    ans[i].push_back(vector<int>());  
                    ans[i].back().push_back(candidates[j]);  
                    continue;  
                } 
                else {  
                    int tmp = i - candidates[j];  
                    for (int m = 0; m < ans[tmp].size(); ++ m) {
                        if (ans[tmp][m].size() >= k) continue; // 2) cut branch. ok too without this.
                        
                        // 3) use "<" instead of "<=" to avoid duplicated number.
                        if (ans[tmp][m].back() < candidates[j]) { 
                            ans[i].push_back(vector<int>(ans[tmp][m]));  
                            ans[i].back().push_back(candidates[j]);  
                        }  
                    }  
                }  // end of if-else
            }  // end of for.
        }  // end of for.
        
        // 4) Get solutions whose size is k.
        vector<vector<int>> v;
        for (int i = 0; i < ans[n].size(); ++ i) {
            if (ans[n][i].size() == k) {
                v.push_back(ans[n][i]);
            }
        }
        
        return v;
    }
};

/**
Combination Sum III
Difficulty: Medium

Find all possible combinations of k numbers that add up to a number n, 
given that only numbers from 1 to 9 can be used and each combination 
should be a unique set of numbers.

Ensure that numbers within the set are sorted in ascending order.

Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]


Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]

 */
