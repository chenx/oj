// Works.
// Makes use of the Postfix notation problem result.
// There should be way of directly build the AST tree without 
// going through the postfix notation first. But this works.
// By: X.C. 4/13/2016

/**
 * Definition of ExpressionTreeNode:
 * class ExpressionTreeNode {
 * public:
 *     string symbol;
 *     ExpressionTreeNode *left, *right;
 *     ExpressionTreeNode(string symbol) {
 *         this->symbol = symbol;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param expression: A string array
     * @return: The root of expression tree
     */
    ExpressionTreeNode* build(vector<string> &expression) {
        // write your code here
        vector<string> v = convertToRPN(expression);
        
        stack<ExpressionTreeNode *> s;
        for (int i = 0, n = v.size(); i < n; ++ i) {
            if (isOp(v[i])) {  // operator
                ExpressionTreeNode * n = new ExpressionTreeNode(v[i]);
                n->right = s.top(); s.pop();
                n->left  = s.top(); s.pop();
                s.push(n);
            }
            else s.push(new ExpressionTreeNode(v[i]));  // number
        }
        return s.empty() ? NULL : s.top();
    }
    
    bool isOp(string s) {
        string ops = "+-*/";
        return ops.find(s) != string::npos;
    }
    
    // Below is the solution to build postfix notation.
    
    vector<string> ans;
    vector<string> convertToRPN(vector<string> &expression) {
        // write your code here
        string s;
        for (auto e : expression) s += e;
        
        ans.clear();
        calculate(s);
        return ans;
    }
    
    int calculate(string s) {
        const char *p = s.c_str();
        return E(p);
    }

    void ignoreSpace(const char*& p) { while (isspace(*p)) ++ p; }
    void expect(const char *& p, char c) { ++ p; }

    int num(const char*& p) {
        int v = 0;
        while (isdigit(*p)) { v = v * 10 + (*p - '0'); ++ p; }
        return v;
    }

    int F(const char *& p) {
        ignoreSpace(p);

        int v = 0;
        if (*p == '(') v = E(++ p), expect(p, ')'); 
        else if (isdigit(*p)) v = num(p), ans.push_back(to_string(v)); 
        else if (! *p) v = 0; 
        //else throw exception(); 


        ignoreSpace(p);
        return v;
    }

    int T(const char *& p) {
        int v = F(p);
        while (*p == '*' || *p == '/') {
            char op = *p;
            if (*p == '*') v *= F(++ p);
            else v /= F(++ p);
            
            ans.push_back(op == '*' ? "*" : "/");
        }
        return v;
    }

    int E(const char *& p) {
        int v = T(p);
        while (*p == '+' || *p == '-') {
            char op = *p;
            if (*p == '+') v += T(++ p);
            else v -= T(++ p);

            ans.push_back(op == '+' ? "+" : "-");
        }
        return v;
    }
};

/**
Expression Tree Build

The structure of Expression Tree is a binary tree to evaluate certain expressions.
All leaves of the Expression Tree have an number string value. All non-leaves of 
the Expression Tree have an operator string value.

Now, given an expression array, build the expression tree of this expression, 
return the root of this expression tree.

Clarification

See wiki:
Expression Tree
Example

For the expression (2*6-(23+7)/(1+2)) (which can be represented by 
["2" "*" "6" "-" "(" "23" "+" "7" ")" "/" "(" "1" "+" "2" ")"]).
The expression tree will be like

                 [ - ]
             /          \
        [ * ]              [ / ]
      /     \           /         \
    [ 2 ]  [ 6 ]      [ + ]        [ + ]
                     /    \       /      \
                   [ 23 ][ 7 ] [ 1 ]   [ 2 ] .

After building the tree, you just need to return root node [-].

 */
