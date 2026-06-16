// Recursive parsing
// From: https://leetcode.com/problems/parse-lisp-expression/editorial/
// Time / Space: O(n^2)
// Should be able to do better with O(n).
class Solution {
    vector<unordered_map<string, int>> scope;
public:
    Solution() {
        scope.push_back(unordered_map<string, int>());
    }

    int evaluate(string expression) {
        scope.push_back(unordered_map<string, int>());
        int ans = evaluate_inner(expression);
        scope.pop_back();
        return ans;
    }

private:
    int evaluate_inner(const string& expression) {
        if (expression[0] != '(') {
            if (isdigit(expression[0]) || expression[0] == '-') {
                return stoi(expression);
            }

            for (int i = scope.size() - 1; i >= 0; --i) {
                if (scope[i].contains(expression))
                    return scope[i][expression];
            }
        }

        vector<string> tokens = expression[1] == 'm' ? // "mult"
            parse(expression.substr(6, expression.size() - 7)) :
            parse(expression.substr(5, expression.size() - 6)) ;
        if (expression.substr(1, 3) == "add") {
            return evaluate(tokens[0]) + evaluate(tokens[1]);
        } else if (expression.substr(1, 4) == "mult") {
            return evaluate(tokens[0]) * evaluate(tokens[1]);
        } else {
            for (int j = 1; j < tokens.size(); j += 2) {
                scope.back()[tokens[j-1]] = evaluate(tokens[j]);
            }
            return evaluate(tokens.back());
        }
    }

    vector<string> parse(const string& expression) {
        vector<string> ans;
        int bal = 0;
        string buf;
        vector<string> tokens = split(expression);
        for (string token: tokens) {
            for (char c: token) {
                if (c == '(') bal++;
                if (c == ')') bal--;
            }
            if (buf.length() > 0) buf += " ";
            buf += token;
            if (bal == 0) { // include only things outside "()"
                ans.push_back(buf);
                buf.clear();
            }
        }
        if (buf.length() > 0)
            ans.push_back(buf);

        return ans;
    }

    vector<string> split(const string& s) {
        stringstream ss(s);
        string out;
        vector<string> result;
        while (getline(ss, out, ' ')) {
            result.push_back(out);
        }
        return result;
    }
};


/**
736. Parse Lisp Expression
Solved
Hard
Topics
conpanies iconCompanies
Hint

You are given a string expression representing a Lisp-like expression to return the integer value of.

The syntax for these expressions is given as follows.

    An expression is either an integer, let expression, add expression, mult expression, or an assigned variable. 
        Expressions always evaluate to a single integer.

    (An integer could be positive or negative.)

    A let expression takes the form "(let v1 e1 v2 e2 ... vn en expr)", where let is always the string "let", then 
        there are one or more pairs of alternating variables and expressions, meaning that the first variable v1 is 
        assigned the value of the expression e1, the second variable v2 is assigned the value of the expression e2, 
        and so on sequentially; and then the value of this let expression is the value of the expression expr.

    An add expression takes the form "(add e1 e2)" where add is always the string "add", there are always two 
        expressions e1, e2 and the result is the addition of the evaluation of e1 and the evaluation of e2.

    A mult expression takes the form "(mult e1 e2)" where mult is always the string "mult", there are always two 
        expressions e1, e2 and the result is the multiplication of the evaluation of e1 and the evaluation of e2.

    For this question, we will use a smaller subset of variable names. A variable starts with a lowercase letter, 
        then zero or more lowercase letters or digits. Additionally, for your convenience, the names "add", "let", 
        and "mult" are protected and will never be used as variable names.

    Finally, there is the concept of scope. When an expression of a variable name is evaluated, within the context 
        of that evaluation, the innermost scope (in terms of parentheses) is checked first for the value of that 
        variable, and then outer scopes are checked sequentially. It is guaranteed that every expression is legal. 
        Please see the examples for more details on the scope.

 

Example 1:

Input: expression = "(let x 2 (mult x (let x 3 y 4 (add x y))))"
Output: 14
Explanation: In the expression (add x y), when checking for the value of the variable x,
we check from the innermost scope to the outermost in the context of the variable we are trying to evaluate.
Since x = 3 is found first, the value of x is 3.

Example 2:

Input: expression = "(let x 3 x 2 x)"
Output: 2
Explanation: Assignment in let statements is processed sequentially.

Example 3:

Input: expression = "(let x 1 y 2 x (add x y) (add x y))"
Output: 5
Explanation: The first (add x y) evaluates as 3, and is assigned to x.
The second (add x y) evaluates as 3+2 = 5.
 */
