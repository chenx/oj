// Iterative version. Works.
class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of unique permutations.
     */
    vector<vector<int> > permuteUnique(vector<int> &nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        if (n == 0) return ans;
        
        ans.push_back({nums[0]});
        
        for (int i = 1; i < n; ++ i) {
            vector<vector<int>> tmp;
            for (int j = 0, m = ans.size(); j < m; ++ j) {
                for (int k = 0; k <= ans[j].size(); ++ k) {
                    vector<int> t = ans[j];
                    if (k > 0 && nums[i] == *(t.begin() + k - 1)) continue; // cut branch. W/o this ok too.
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

