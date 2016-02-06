// Another solution:
// https://leetcode.com/discuss/81478/easy-short-concise-and-fast-java-dfs-3-ms-solution

// Works. From: https://leetcode.com/discuss/68272/straight-forward-solution-with-explanation
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int maxv = 0;
        vector<string> res;
        dfs(res, maxv, s, "", 0, 0);
        if (res.size() == 0) res.push_back("");
        return res;
    }

    void dfs(vector<string> &res, int &maxv, string str, string subRes, int countLeft, int maxLeft){
        if (str == "") {
            if (countLeft == 0 && subRes != "") {
                if (maxLeft > maxv) maxv = maxLeft;
                if (maxv == maxLeft && 
                    find(res.begin(), res.end(), subRes) == res.end()) res.push_back(subRes);
            }
            return;
        }
        
        if (str[0] == '(') {
            dfs(res, maxv, str.substr(1), subRes + '(', countLeft + 1, maxLeft + 1);
            dfs(res, maxv, str.substr(1), subRes, countLeft, maxLeft);
        } else if (str[0] == ')') {
            if (countLeft > 0) {
                dfs(res, maxv, str.substr(1), subRes + ')', countLeft - 1, maxLeft);
            }
            dfs(res, maxv, str.substr(1), subRes, countLeft, maxLeft);
        } else {
            dfs(res, maxv, str.substr(1), subRes + str[0], countLeft, maxLeft);
        }
    }
};


/**
Remove Invalid Parentheses
Difficulty: Hard

Remove the minimum number of invalid parentheses in order to 
make the input string valid. Return all possible results.

Note: The input string may contain letters other than the 
parentheses ( and ).

Examples:

"()())()" -> ["()()()", "(())()"]
"(a)())()" -> ["(a)()()", "(a())()"]
")(" -> [""]
 */
