// Works. From https://leetcode.com/problems/remove-invalid-parentheses/editorial/
class Solution3 {
    set<string> validExpressions;

    void recurse(string& s, int index, int leftCount, int rightCount, int leftRem, int rightRem,
      string& expression) {
        // If we reached the end of the string, just check if the resulting expression is
        // valid or not and also if we have removed the total number of left and right
        // parentheses that we should have removed.
        if (index == s.length()) {
            if (leftRem == 0 && rightRem == 0) {
                validExpressions.insert(expression);
            }
            return;
        } 
        
        char character = s[index];
        int length = expression.length();

        // The discard case. Note that here we have our pruning condition.
        // We don't recurse if the remaining count for that parenthesis is == 0.
        if ((character == '(' && leftRem > 0) || (character == ')' && rightRem > 0)) {
            recurse(s, index + 1, leftCount, rightCount,
                    leftRem - (character == '(' ? 1 : 0),
                    rightRem - (character == ')' ? 1 : 0),
                    expression);
        }
        expression += character;

        // Simply recurse one step further if the current character is not a parenthesis.
        if (character != '(' && character != ')') {
            recurse(s, index + 1, leftCount, rightCount, leftRem, rightRem, expression);
        } else if (character == '(') {
            // Consider an opening bracket.
            recurse(s, index + 1, leftCount + 1, rightCount, leftRem, rightRem, expression);
        } else if (rightCount < leftCount) {
            // Consider a closing bracket.
            recurse(s, index + 1, leftCount, rightCount + 1, leftRem, rightRem, expression);
        }

        // Delete for backtracking.
        expression = expression.substr(0, expression.length() - 1);
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        int left = 0, right = 0;
        // First, we find out the number of misplaced left and right parentheses.
        for (int i = 0; i < s.length(); i++) {
            // Simply record the left one.
            if (s[i] == '(') {
                left ++;
            } else if (s[i] == ')') {
                // If we don't have a matching left, then this is a misplaced right, record it.
                right = left == 0 ? right + 1 : right;

                // Decrement count of left parentheses because we have found a right
                // which CAN be a matching one for a left.
                left = left > 0 ? left - 1 : left;
            }
        }

        string p;
        recurse(s, 0, 0, 0, left, right, p);
        return vector<string>(validExpressions.begin(), validExpressions.end());
    }
};

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
