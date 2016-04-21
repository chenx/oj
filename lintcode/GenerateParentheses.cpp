class Solution {
public:
    /**
     * @param n n pairs
     * @return All combinations of well-formed parentheses
     */
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        gen(ans, n, 0, 0, "");
        return ans;
    }
    
    void gen(vector<string> & ans, int n, int L, int R, string p) {
        if (L == n && R == n) {
            ans.push_back(p);
            return;
        }
        
        if (L > R) gen(ans, n, L, R + 1, p + ")");
        if (L < n) gen(ans, n, L + 1, R, p + "(");
    }
};
