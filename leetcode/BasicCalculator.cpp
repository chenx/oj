
// E = F | { F +- F }
// F = (E) | num
class Solution {
public:
    int calculate(string s) {
        const char *p = s.c_str();
        return E(p);
    }
        
    void MyEx(string msg) {
        cout << "exception: " << msg << endl;
        throw exception();
    }

    void getToken(const char*& p) { while (isspace(*p)) ++ p; }
    bool is_num(const char c) { return c >= '0' && c <= '9'; }
    
    int num(const char*& p) {
        getToken(p);
        if (*p == '0') {
            ++ p;
            if (is_num(*p)) MyEx("num(): number does not start with 0");
            else return 0;
        }
        else if (is_num(*p)) {
            int v = 0;
            while (is_num(*p)) { v = v * 10 + (*p - '0'); ++ p; }
            return v;
        }
        else {
            MyEx("num(): unknown type");
        }
    }

    int F(const char *& p) {
        getToken(p);
        if (*p == '(') {
            int v = E(++ p);
            if (*p == ')') { ++ p; return v; }
            else MyEx("F(): no end )");
        }
        else if (is_num(*p)) {
            return num(p);
        }
        else {
            char c = *p;
            string chr = string(&c);
            MyEx( "F(): unknown char '" + chr + "'" );
        }
    }
    
    int E(const char *& p) {
        int v = F(p);
    
        getToken(p);
        while (*p == '+' || *p == '-') {
            char op = *p;
            int u = F(++ p);
            if (op == '+') v += u;
            else if (op == '-') v -= u;
            getToken(p);
        }
        return v;
    }
};

// from: https://leetcode.com/discuss/62293/a-standard-recursive-descent-solution-in-c
// #=== EBNF ===#
// exp = term {addop term}
// term = factor {mulop factor} 
// factor = (exp) | number
// (in this problem, * and / is unnecessary to be considered, so we can delete the term level)
class Solution {
public:
    int calculate(string str) {
        deleteBlank(str);
        s = str;
        index = 0;
        return exp();
    }

private:
    string s;   /*string after stripping blanks*/
    int index;  /*record the position*/

    /* one charactor is 'eaten' when match() is called */
    void match(char c = 0){
        //'c' here is used to make sure token == c
        //for example, test if there is a ')' in the function factor()
        //but indeed, since the input are all valid exp, this test is unnecessary
        //you can simply replace this function with statement `++index`.
        ++index;
    }

    /* recursion descent part */

    //exp -> term addop term | term
    //addop -> + | -
    int exp(){
        int ret = term();
        while(s[index] == '+' || s[index] == '-'){
            switch(s[index]){
                case '+':
                match('+');
                ret += term();
                break;

                case '-':
                match('-');
                ret -= term();
                break;
            }
        }
        return ret;
    }
    //term -> factor mulop factor | factor
    //mulop -> * | /
    int term(){
        int ret = factor();
        while(s[index] == '*' || s[index] == '/'){
            switch(s[index]){
                case '*':
                match('*');
                ret *= factor();
                break;

                case '/':
                match('/');
                ret /= factor();
                break;
            }
        }
        return ret;
    }
    //factor -> (exp) | number
    //number -> (0|1|2|...|9)+
    int factor(){
        int ret;
        if(s[index] == '('){
            match('(');
            ret = exp();
            match(')');
        }else if(isdigit(s[index])){
            ret = s[index]-'0';
            match();
            while(index<s.size() && isdigit(s[index])){
                ret = ret*10 + (s[index] -'0');
                match();
            }
        }else{
            ;//error, won't happen here
        }
        return ret;
    }
    //a simple function used to strip all the blanks.
    void deleteBlank(string& s){
        int write = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=' ') s[write++] = s[i];
        }
        s.resize(write);
    }
};


class Solution3 {
public:
    int calculate(string s) {
        stack <int> nums, ops;
        int num = 0;
        int rst = 0;
        int sign = 1;
        for (char c : s) { 
            if (isdigit(c)) {
                num = num * 10 + c - '0';
            }
            else {
                rst += sign * num;
                num = 0;
                if (c == '+') sign = 1;
                if (c == '-') sign = -1;
                if (c == '(') {
                    nums.push(rst);
                    ops.push(sign);
                    rst = 0;
                    sign = 1;
                }
                if (c == ')' && ops.size()) {
                    rst = ops.top() * rst + nums.top();
                    ops.pop(); nums.pop();
                }
            }
        }
        rst += sign * num;
        return rst;
    }
};


// This classic solution works for both Basic Calculators I and II.
// See: The classic solution: http://www.engr.mun.ca/~theo/Misc/exp_parsing.htm 
// E = T | { T +- T }
// T = F | { F */ F }
// F = (E) | num
class Solution {
public:
    int calculate(string s) {
        const char *p = s.c_str();
        return E(p);
    }
        
    void MyEx(string msg) {
        cout << "exception: " << msg << endl;
        throw exception();
    }

    void getToken(const char*& p) { while (isspace(*p)) ++ p; }
    bool is_num(const char c) { return c >= '0' && c <= '9'; }
    
    int num(const char*& p) {
        getToken(p);
        if (*p == '0') {
            ++ p;
            if (is_num(*p)) MyEx("num(): number does not start with 0");
            else return 0;
        }
        else if (is_num(*p)) {
            int v = 0;
            while (is_num(*p)) { v = v * 10 + (*p - '0'); ++ p; }
            return v;
        }
        else {
            MyEx("num(): unknown type");
        }
    }

    int F(const char *& p) {
        getToken(p);
        if (*p == '(') {
            int v = E(++ p);
            if (*p == ')') { ++ p; return v; }
            else MyEx("F(): no end )");
        }
        else if (is_num(*p)) {
            return num(p);
        }
        else {
            char c = *p;
            string chr = string(&c);
            MyEx( "F(): unknown char '" + chr + "'" );
        }
    }
    
    int T(const char *& p) {
        int v = F(p);
    
        getToken(p);
        while (*p == '*' || *p == '/') {
            char op = *p;
            int u = F(++ p);
            if (op == '*') v *= u;
            else if (op == '/') v /= u;
            getToken(p);
        }
        return v;
    }  
    
    int E(const char *& p) {
        int v = T(p);
    
        getToken(p);
        while (*p == '+' || *p == '-') {
            char op = *p;
            int u = T(++ p);
            if (op == '+') v += u;
            else if (op == '-') v -= u;
            getToken(p);
        }
        return v;
    }
};

/**
Basic Calculator
Difficulty: Medium

Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), 
the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:

"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23

Note: Do not use the eval built-in library function. 
 */
