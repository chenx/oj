// Another solution:
// https://leetcode.com/discuss/81478/easy-short-concise-and-fast-java-dfs-3-ms-solution

// Works. Modified from Solution to be more clear.
class Solution2 {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        int maxLeftCount = 0;
        dfs(res, s, "", 0, 0, maxLeftCount);
        if (res.size() == 0) res.push_back("");
        return res;
    }

    // s: input string; p: valid parentheses string; diff: # of '(' minus # of ')';
    // leftCount: number of '(' in valid p. maxLeftCount: max value of leftCount.
    void dfs(vector<string> &res, string s, string p, int diff, int leftCount, int & maxLeftCount){
        if (s == "") {
            if (diff == 0 && p != "") {
                maxLeftCount = max(maxLeftCount, leftCount);
                if (maxLeftCount == leftCount && 
                    find(res.begin(), res.end(), p) == res.end()) {
                    res.push_back(p);
                }
            }
            return;
        }
        
        if (s[0] == '(') {
            dfs(res, s.substr(1), p + '(', diff + 1, leftCount + 1, maxLeftCount); 
            dfs(res, s.substr(1), p, diff, leftCount, maxLeftCount); // remove this '('.
        } else if (s[0] == ')') {
            if (diff > 0) dfs(res, s.substr(1), p + ')', diff - 1, leftCount, maxLeftCount);
            dfs(res, s.substr(1), p, diff, leftCount, maxLeftCount); // remove this ')'.
        } else {
            dfs(res, s.substr(1), p + s[0], diff, leftCount, maxLeftCount); // ignore letter.
        }
    }
};

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
