/* Works. Further cleaned from Solution7, and ignored unnecessary details. Very good.
 * http://www.engr.mun.ca/~theo/Misc/exp_parsing.htm
    G := E + E | E - E
    E := num | '(' G ')'
 */
class Solution9 {
public:
    int calculate(string s) {
        const char* p = s.c_str();
        int v = G(p);
        expect(p, '\0');
        return v;
    }

    int G(const char*& p) {
        int v = E(p);
        while (*p == '+' || *p == '-') {
            if (*p == '+') v += E(++ p);
            else v -= E(++ p);
        }
        return v;
    }

    int E(const char*& p) {
        ignoreSpace(p);

        int v = 0;
        // Note: this if condition is needed. If no match it'll try -E.
        // Otherise for '-' E, it'll eat this '-' can get error/
        if (*p == '(') {
            v = G(++ p);
            expect(p, ')');
            ++ p;
        } else {
            while (isdigit(*p)) {
                v = v * 10 + (*p - '0');
                ++ p;
            }
        }

        ignoreSpace(p);
        return v;
    }

    void expect(const char *& p, char c) {
        if (*p != c) throw exception();
    }

    void ignoreSpace(const char *& p) {
        while (isspace(*p)) ++ p;
    }
};

/* Works. Further cleaned from Solution7, and ignored unnecessary details. Very good.
 * http://www.engr.mun.ca/~theo/Misc/exp_parsing.htm
    E --> F {( "+" | "-" ) F}
    F --> G | "-" G
    G --> num | "(" E ")"

    Include * and /:
    E --> T {( "+" | "-" ) T}
    T --> F {( "*" | "/" ) F}
    F --> G | "-" G
    G --> num | "(" E ")"
 * Note: F could be: - T
 */
class Solution8 {
public:
    int calculate(string s) {
        const char *p = s.c_str();
        int v = E(p);
        if (*p != '\0') throw exception();
        return v;
    }

    void ignoreSpace(const char*& p) { while (isspace(*p)) ++ p; }
    void expect(const char *& p, char c) {
        if (c != *p) {
            throw exception();
        }
        ++ p; 
    }

    int num(const char*& p) {
        int v = 0;
        while (isdigit(*p)) { v = v * 10 + (*p - '0'); ++ p; }
        return v;
    }

    int F(const char *& p) {
        ignoreSpace(p);

        int v = 0;
        if (*p == '(') v = E(++ p), expect(p, ')'); 
        else if (isdigit(*p)) v = num(p); 

        ignoreSpace(p);
        return v;
    }

    int E(const char *& p) {
        int v = F(p);
        while (*p == '+' || *p == '-') {
            if (*p == '+') v += F(++ p);
            else v -= F(++ p);
        }
        return v;
    }

    // Use this if including * and / from T().
    int E2(const char *& p) {
        int v = T(p);
        while (*p == '+' || *p == '-') {
            if (*p == '+') v += T(++ p);
            else v -= T(++ p);
        }
        return v;
    }

    int T(const char *& p) {
        int v = F(p);
        while (*p == '*' || *p == '/') {
            if (*p == '*') v *= F(++ p);
            else v /= F(++ p);
        }
        return v;
    }
};

// Works. Best so far.  Works for both BasicCalculator and BasicCalculator_II.
// use isdigit(), and expect. Put all ignoreSpace() to F().
/*
 * http://www.engr.mun.ca/~theo/Misc/exp_parsing.htm
    E --> T {( "+" | "-" ) T}
    T --> F {( "*" | "/" ) F}
    F --> num | "(" E ")"
 * Note: F could be: - T
 */
class Solution7 {
public:
    int calculate(string s) {
        const char *p = s.c_str();
        return E(p);
    }

    void ignoreSpace(const char*& p) { while (isspace(*p)) ++ p; }
    void expect(const char *& p, char c) {
        if (*p != c) {
            cout << "error: expect: " << c << endl;
            throw exception();
        }
        ++ p;
    }

    int num(const char*& p) {
        int v = 0;
        while (isdigit(*p)) { v = v * 10 + (*p - '0'); ++ p; }
        return v;
    }

    int F(const char *& p) {
        ignoreSpace(p);

        int v = 0;
        if (*p == '(') {
            v = E(++ p);
            expect(p, ')');
        }
        else if (isdigit(*p)) {
            v = num(p);
        }
        else if (! *p) { // useful for situation such as input is "".
            v = 0;
        }
        else {
            cout << "F: invalid input: " << p  << endl;
            throw exception();
        }

        ignoreSpace(p);
        return v;
    }

    int T(const char *& p) {
        int v = F(p);

        while (*p == '*' || *p == '/') {
            char op = *p;
            int u = F(++ p);
            if (op == '*') v *= u;
            else if (op == '/') v /= u;
        }
        return v;
    }

    int E(const char *& p) {
        int v = T(p);

        while (*p == '+' || *p == '-') {
            char op = *p;
            int u = T(++ p);
            if (op == '+') v += u;
            else if (op == '-') v -= u;
        }
        return v;
    }
};



// Works. Best answer so far. Simplified from Solution2 of BasicCalculator_II,
// by removing function F().
class Solution6 {
public:
    /*
    E = T | T + T | T - T
    F = (E) | num
    */
    int calculate(string s) {
        const char * p = s.c_str();
        return E(p);
    }

    int E(const char *& p) {
        int n = T(p);
        while (*p == '+' || *p == '-') {
            char op = *p;
            ++ p;
            int m = T(p);
            if (op == '+') n += m;
            else n -= m;
        }
        return n;
    }

    int T(const char *& p) {
        if (isNum(p)) {
            return num(p);
        }
        else {
            expect(p, '(');
            int n = E(p);
            expect(p, ')');
            return n;
        }
    }

    int num(const char *& p) {
        ignoreSpace(p);

        int v = 0;
        while (isDigit(*p)) {
            v = v * 10 + *p - '0';
            ++ p;
        }
        ignoreSpace(p);

        return v;
    }
    
    void expect(const char *& p, char c) {
        ignoreSpace(p);
        if (*p == c) {
            ++ p;
            return;
        }
        // print error msg.
        throw exception();
    }
    
    bool isNum(const char * p) {
        while (isspace(*p)) ++ p;
        return isdigit(*p);
    }
    
    bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }
    
    void ignoreSpace(const char *& p) {
        while (isspace(*p)) ++ p;
    }
};

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
class Solution4 {
public:
    int calculate(string s) {
        const char *p = s.c_str();
        return E(p);
    }
        
    void MyEx(string msg) {
        cout << "exception: " << msg << endl;
        throw exception();
    }

    void ignoreSpace(const char*& p) { while (isspace(*p)) ++ p; }
    bool is_num(const char c) { return c >= '0' && c <= '9'; }
    
    int num(const char*& p) {
        ignoreSpace(p);
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
        ignoreSpace(p);
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
    
        ignoreSpace(p);
        while (*p == '*' || *p == '/') {
            char op = *p;
            int u = F(++ p);
            if (op == '*') v *= u;
            else if (op == '/') v /= u;
            ignoreSpace(p);
        }
        return v;
    }  
    
    int E(const char *& p) {
        int v = T(p);
    
        ignoreSpace(p);
        while (*p == '+' || *p == '-') {
            char op = *p;
            int u = T(++ p);
            if (op == '+') v += u;
            else if (op == '-') v -= u;
            ignoreSpace(p);
        }
        return v;
    }
};

// Works. Simplified from Solution4, assuming string is valid.
//    E = T | T + T | T - T
//    T = F | F * F | F / F
//    F = (E) | num
class Solution5 {
public:
    int calculate(string s) {
        const char *p = s.c_str();
        return E(p);
    }

    void ignoreSpace(const char*& p) { while (isspace(*p)) ++ p; }
    bool is_num(const char c) { return c >= '0' && c <= '9'; }
    
    int num(const char*& p) {
        ignoreSpace(p);
        int v = 0;
        while (is_num(*p)) { v = v * 10 + (*p - '0'); ++ p; }
        return v;
    }

    int F(const char *& p) {
        ignoreSpace(p);
        if (*p == '(') {
            int v = E(++ p);
            ++ p; // ignore ')'
            return v; 
        }
        else if (is_num(*p)) {
            return num(p);
        }
    }
    
    int T(const char *& p) {
        int v = F(p);
    
        ignoreSpace(p);
        while (*p == '*' || *p == '/') {
            char op = *p;
            int u = F(++ p);
            if (op == '*') v *= u;
            else if (op == '/') v /= u;
            ignoreSpace(p);
        }
        return v;
    }  
    
    int E(const char *& p) {
        int v = T(p);
    
        ignoreSpace(p);
        while (*p == '+' || *p == '-') {
            char op = *p;
            int u = T(++ p);
            if (op == '+') v += u;
            else if (op == '-') v -= u;
            ignoreSpace(p);
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
