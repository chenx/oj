//
// Solution1 is most complete.
// Solution2 and Solution3 do not accept empty space, or +- before a number.
//
// In general, methods: 
// 1) build AST
// 2) recursive descent
// 3) use stack - The shunting yard algorithm.
//
// @Author: Xin Chen
// @Created On: 2/5/2013
// @Last Modfied: 2/6/2013
//

#include <iostream>
#include <cmath> // for pow()
using namespace std;

// works for simple cases, but not recommended.
class Solution3 {
public:
    double readNumber(const char * &str) {
         double num;
         sscanf(str, "%lf", &num);
    
         for (++str; isdigit(*str) || *str == '.'; ++str)
             ;
    
         return num;
    }
    
    double calculate(const char * str) {
         if (*str == '\0')  return 0.0;
    
         double result = 1.0;
         char op = '*';
         while (op == '*' || op == '/') {
             if (op == '*')
                 result *= readNumber(str);
             else
                 result /= readNumber(str);
    
             op = *str++;
         }
    
         return result + calculate(--str);
    }
};

//
// Recursive descent.
// 
// http://www.engr.mun.ca/~theo/Misc/exp_parsing.htm
// http://www.mitbbs.com/article_t/JobHunting/32319835.html
// @Author: wwwyhx
// Recursive descent:
// Add = mul (+- mul)*
// mul = num (*/ num)*
// num = (+-)[0-9]*
// Note: iteration is used, so this is not strict recursive descent.
// This also only accepts correct input.
// 
class Solution2 {
public:
    double Add(const char*& p) {
        double res = mul(p);
        while (*p == '+' || *p == '-') {
            if (*p == '+') res += mul(++p);
            else res -= mul(++p);
        }
   
        return res;
    }
    
    double mul(const char*& p) {
        double res = num(p);
        while (*p == '*' || *p == '/') {
            if (*p == '*') res *= num(++p);
            else res /= num(++p);
        }
    
        return res;
    }
    
    double num(const char*& p) {
        while (isspace(*p)) ++ p; // this allows space to be skipped.

        bool bNeg = false;
        if (*p == '-') {
            bNeg = true;
            p++;
        }
    
        int res = 0;
        while (*p >= '0' && *p <= '9') res = res*10 + *p++ - '0';
    
        return bNeg ? -res : res;
    }
};


// This builds an AST and evaluate it.
// to improve:
// - allow number to have multiple digits. (done)
// - allow neg number: (done, allow +/- before a number) (done)
// - allow number to be of format: .3 -> 0.3 (done)
// - allow parenthesis '()'. (done)
// - check for invalid input - not: operand [operator, operand]+. (done)
// - allow '^' for power operation. (done)
// See here for a more complete implementation: 
// http://www2.hawaii.edu/~chenx/alg/expr_parser/expr_tree.c

struct Node {
    double val;
    char op;
    int op_prec; // precedence of operator
    int type; // 0 - operand, 1 - operator
    Node * left;
    Node * right;
    Node(double _val, char _op, int _type) : val(_val), op(_op), type(_type), left(NULL), right(NULL) {}
};

class Solution {
private:
    int prec_base;
    const char * p0; // record start position of input string.
    
    void err(char * msg, const char * p) {
        printf("input error: %s, at input position %d\n", msg, p - p0);
        printf("%s\n", p0);
        for (int i = 0, len = p - p0; i < len; ++ i) putchar(' ');
        printf("^\n");
        exit(1);
    }

    void dump_node(Node * n) {
        if (n->type == 0) printf(" %.1lf ", n->val);
        else printf(" %c ", n->op);
    }
    
    void dump(Node * n) {
        if (! n) return;
        if (! n->left && ! n->right) {
            dump_node(n); 
            return;
        }
        
        printf("(");
        dump(n->left);
        dump_node(n); 
        dump(n->right);
        printf(")");
    }
    
    // get precedence.
    int prec(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        if (op == '^') return 3;
        return 0;
    }
    
    // get type: operand or operator.
    int isOp(char c) { 
        return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^'); 
    }
    
    int isDigit(char c) { return c >= '0' && c <= '9'; }
    
    // type - desired type of new token.
    Node * getNextToken(const char *& input, int type) {
        const int prec_base_inc = 4; // 1 + max(op prec)
        while (isspace(*input)) ++ input; // skips spaces.
        
        if (! *input) return NULL; // end of input.

        while (*input == '(') {
            prec_base += prec_base_inc;
            ++ input;
        }
        
        // check if is desired type.
        if (! ((type == 1 && isOp(*input) ) ||
               (type == 0 && (isDigit(*input) || *input == '+' || *input== '-' || *input=='.'))) ) {
            err("wrong type of operand/operator", input);
        }
        
        Node * n;        
        if (type == 1) { // operator.
            n = new Node(0, *input, type); 
            n->op_prec = prec(n->op) + prec_base;
            ++ input;
        }
        else { // type == 0: operand.
            double val;
            sscanf(input, "%lf", &val); // sscanf requires no space between sign and value.
            n = new Node(val, 0, type);
            if (*input == '+' || *input == '-') ++ input;
            if (! (isDigit(*input) || *input == '.')) {
                err("incomplete number", input);
            }
            
            bool dot_used = false; // allow only one dot.
            while ( isDigit(*input) || (*input == '.' && !dot_used)) {
                  if (*input == '.') dot_used = true;
                  ++ input;
            }
            
            while (*input == ')') {
                prec_base -= prec_base_inc;
                ++ input;
            }
        }
        
        return n;
    }
    /*
    // this works, but when input = " 3 / (4+2)*(3-1) + 1",
    // evaluation order will be (3 / ((4+2)*(3-1)) + 1. 
    // This does not change the result, but it's not natural anyway.
    void build(const char * input, Node *& root) {
        if (! *input) {
            err("build: ends without operand", input);
            return;
        }
        
        dump(root); puts("");
        
        Node * opd = getNextToken(input, 0); 
        if (! *input) {
            root->right = opd;
            return;
        }
        
        Node * opt = getNextToken(input, 1); 

        if (opt->op_prec > root->op_prec) {
            opt->left = opd;
            printf("1. root: %c (prec: %d), opt: %c (prec: %d)\n", root->op, root->op_prec, opt->op, opt->op_prec);
            build(input, opt);
            //root->right = opt; // can just use this if not use '()'
            printf("2. root: %c (prec: %d), opt: %c (prec: %d)\n", root->op, root->op_prec, opt->op, opt->op_prec);
            if (opt->op_prec > root->op_prec) {
                root->right = opt; 
            } else {
                printf("switch root from %c to %c\n", root->op, opt->op);
                root->right = opt->left;
                opt->left = root;
                root = opt;
            }
        } else {
            root->right = opd;
            opt->left = root;
            build(input, opt);
            root = opt; 
        }
    }
    
    void buildAST(const char * input, Node *& p) {
        if (! *input) return;
        
        Node * opd = getNextToken(input, 0);
        if (! *input) {
            p = opd;
            return;
        }
        
        Node * opt = getNextToken(input, 1);
        opt->left = opd;
        
        build(input, opt);    
        p = opt;
    }
    */
    
    /* 
    // This is tail recursion, so can be made into iteration.
    void build(const char * input, Node *& root) {
        Node * opt = getNextToken(input, 1);         
        if (! opt) return; // end of input.
        
        Node * opd = getNextToken(input, 0); 
        
        if (root->type == 0 || opt->op_prec <= root->op_prec) {
            opt->left = root;
            opt->right = opd;
            root = opt;
        } else {
            // insert opt above the operand node, or the first operator node x
            // where opt.prec <= x.prec.
            Node * n = root;
            while (1) {
                if (n->right->type == 0 || opt->op_prec <= n->right->op_prec) {
                    opt->left = n->right;
                    opt->right = opd;
                    n->right = opt;
                    break;
                } else {
                    n = n->right;
                }
            }
        }
        
        build(input, root);
    } 
    
    void buildAST(const char * input, Node *& p) {
        p = getNextToken(input, 0);
        build(input, p);
    }
    */

    void buildAST(const char * input, Node *& root) {
        root = getNextToken(input, 0);
        
        while (1) {
            Node * opt = getNextToken(input, 1);         
            if (! opt) return; // end of input.
            
            Node * opd = getNextToken(input, 0); 
            
            if (root->type == 0 || opt->op_prec <= root->op_prec) {
                opt->left = root;
                opt->right = opd;
                root = opt;
            } else {
                // insert opt above the operand node, or the first operator node x
                // where opt.prec <= x.prec.
                Node * n = root;
                while (1) {
                    if (n->right->type == 0 || opt->op_prec <= n->right->op_prec) {
                        opt->left = n->right;
                        opt->right = opd;
                        n->right = opt;
                        break;
                    } else {
                        n = n->right;
                    }
                } // end of while
            } // end of if   
        } // end of while
    }
    
    double eval(Node * t) {
        if (! t) return 0;
        if (t->type == 0) return t->val; // t is operand.
        
        // t is operator.
        if (t->op == '+') return eval(t->left) + eval(t->right);
        if (t->op == '-') return eval(t->left) - eval(t->right);
        if (t->op == '*') return eval(t->left) * eval(t->right);
        if (t->op == '/') return eval(t->left) / eval(t->right);
        if (t->op == '^') return pow(eval(t->left), eval(t->right));
    }
    
public:
    Solution() { prec_base = 0; }
    ~Solution() { /* destroy AST. */ } 
    
    double calc(const char * s) {
        p0 = s; // record start pointer position.
        
        Node * p = NULL;
        buildAST(s, p);
        dump(p); puts("");
        
        return eval(p);
    }
};

int main() {
      const char * input = "(1 + 2)*((3-1)- 3.5)/2 + 4^2"; // = 6
//    const char * input = "2*3 / (4 + 2)*((3-1)- 3.5) + 4"; // = 2.5
//    const char * input = "2 * 3 / (4 + 2)*(3-1) "; // = 6
//    const char * input = " 3 / (4+2)*(3-1) + 1";// + 4"; = 2
    const char * input2 = strdup(input); 
    
    Solution s;
    cout << "Solution 1: " << s.calc(input) << endl;
    
    Solution2 s2;
    cout << "solution 2: " << s2.Add( input ) << endl;
    
    Solution3 s3;
    cout << "Solution 3: " << s3.calculate( input2 );
    return 0;
}

/*
// Has error, can't run 1+2*3 - 1 etc..
//#include "stdafx.h"
#include <string>
#include <stdio.h>
#include <iostream>
using namespace std;

int stringCalculator(string input, int factor, char sign)
{
    int len = input.length();
    if (len == 0) return 0;
    int i = 0;
    while (i< len && input[i]>='0' && input[i]<='9')
    {
        ++i;
    }
    int rightEnd = min (len, i);
    int operand = atoi(input.substr(0,rightEnd).c_str());
    if (sign == '*')
        operand *= factor;
    else
        operand /= factor;
    if (i == len)
        return operand;
    else
    {
        switch (input[i])
        {
        case '+':
            return operand+stringCalculator(input.substr(i+1), 1, '*');
        case '-':
            return operand-stringCalculator(input.substr(i+1), 1, '*');
        default:
            return stringCalculator(input.substr(i+1), operand, input[i]);
            break;
        }
    }
}

int calculator (string input)
{
    return stringCalculator(input,1,'*');
}

int main(int argc, char* argv[])
{
    string test = "1+2*3";
    cout << calculator (test);
    cin.get();
    return 0;
}
*/
