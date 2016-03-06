#include <iostream>
using namespace std;

// Works too. Tested. Do not use pointer, just array index.
class Solution6 {
public:
    void reverseWords(string &s) {
        s = removeSpace(s); // do this before get n.
        
        int i = 0, j, n = s.length();

        while (true) {
            while (i < n && isspace(s[i])) ++ i;
            if (i == n) break;
            
            j = i; // j = i+1 works too.
            while (j < n && ! isspace(s[j])) ++ j;
            -- j;
            rev(s, i, j);
            //reverse(s.begin() + i, s.begin() + j + 1); // this works too.
            
            i = j + 1;
        }
        
        rev(s, 0, s.length() - 1);
    }
    
    // remove starting and trailing spaces, combine multiple spaces into one.
    string removeSpace(string s) {
        int n = s.length(), i = 0;
        string t = "";
        
        while (i < n && isspace(s[i])) ++ i;
        if (i == n) return t;
        
        while (true) {
            if (t != "") t += " ";
            while (i < n && ! isspace(s[i])) t += s[i ++];
            if (i == n) break;
            while (i < n && isspace(s[i])) ++ i;
            if (i == n) break;
        }
        
        return t;
    }
    
    void rev(string &s, int i, int j) {
        for (; i < j; ++ i, -- j) 
            swap(s[i], s[j]);
    }
};

// This works too. 2/5/2016
class Solution5 {
public:
    void reverseWords(string &s) {
        string r = "", t = "";
        bool inWord = false;
        
        for (int i = 0; i < s.length(); ++ i) {
            if (isspace(s[i])) {
                if (inWord) {
                    r = (r == "") ? t : (t + " " + r);
                    t = "";
                    inWord = false;
                }
            }
            else {
                if (! inWord) {
                    inWord = true;
                    t = s[i];
                }
                else {
                    t += s[i];
                }
            }
        }

        if (t != "") r = (r == "") ? t : (t + " " + r);

        s = r;
    }
};

// This works too.
class Solution4 {
public:
    void reverseWords(string &s) {
        string t = "";
        trim(s); 

        char * p = (char *) s.c_str(), * p1 = p, * q, * next;
        
        // reverse entire string.
        for (q = p; *q; ++ q) {}
        -- q;
        rev(p1, q); 
        
        // reverse each substring.
        while (*p) {
            if (*p == ' ') ++ p;
            if (! *p) break;
            
            for (q = p; *q && *q != ' '; ++ q) {}
            next = q; // next non empty char, or end of string.
            -- q;
            
            rev((char *) p, (char *) q);
            
            p = next;
        }
        
    }
    
    void trim(string &s) {
        char * p = (char *) s.c_str(), * head = p, * i = p;

        while (1) {
            while (*i == ' ') ++ i;
            if (! *i) { *p = '\0'; break; }
            if (p != head) *p ++ = ' '; 
            while (*i && *i != ' ') *p ++ = *i ++;
        }

        s = s.c_str();
    }
    
    void rev(char * p, char * q) {
        while (p < q) {
            char c = *p;
            *p = *q;
            *q = c;
            ++ p, -- q;
        }
    }
};

// This works too. Is most succinct.
// Idea is: for "  w1   w2   w3 ", in each cycle, ignore space, until wn is found,
// when getting wn, reverse it on the way, and add wn_reverse to final string t: 
// if t is empty, add as wn_reverse; else, add as " " + wn_reverse.
// This saves the trouble of a removeSpace() function.
// Finally, reverse entire string t.
// By: X.C., 01/22/2015.
class Solution3 {
public:
    void reverseWords(string &s) {
        string t;
        int n = s.length();
        
        for (int i = 0; i < n; ) {
            for (; s[i] == ' ' && i < n; ++ i) {}
            
            string tmp;
            for (; s[i] != ' ' && i < n; ++ i) {
                tmp = s[i] + tmp; // reverse current word.
            }
            if (tmp == "") continue;
            
            if (t == "") t = tmp;
            else t += " " + tmp;
        }
        
        reverse(t.begin(), t.end());
        s = t;
    }
};

// This works.
class Solution {
public:
    void reverseWords(string &s) {
        if (s.length() == 0) return;
        
        char * b, * e, * p;
        p = (char*) s.c_str();
        
        b = e = p; 
        while (*e) ++ e;
        -- e;
        rev(b, e);

        while (1) {
            b = p;
            while (isspace(*b)) ++ b;
            if (! *b) {
                break;
            }
            
            e = b + 1;
            while (*e && ! isspace(*e)) ++ e;

            p = e;
            -- e;
            
            rev(b, e); // do reverse
        }
        
        removeSpace(s); // can go to under first line too.
    }
    
    void removeSpace(string &s) {
        // now remove extra spaces
        char * b, * p;
        
        b = p = (char*) s.c_str();
        while (isspace(*b)) ++ b;
        
        while (1) {
            if (! *b) {
                *p = '\0';
                break;
            }
            while (*b && ! isspace(*b)) {
                *p = *b; ++ p; ++ b;
            }
            
            if (isspace(*b)) {
                while (isspace(*b)) ++ b;
                if (*b) {
                    *p = ' '; ++ p; 
                }
            }
        }
        
        s = s.c_str(); // needed! Seems for some reason "*p = '\0'" is not working.
    }
    
    void rev(char * b, char * e) {
        while (b < e) {
                char c = *b;
                *b = *e;
                *e = c;
                ++ b, -- e;
        }         
    }
         
    bool isspace(char c) {
        return c == ' ' || c == '\t' || c == '\n';
    }
    
};


// This also works.
class Solution2 {
public:
    void reverseWords(string &s) {
        int a = 0, b = 0, p = 0, n = s.length();
        
        removeSpace(s); /*
        for (a = 0; a < n && isspace(s[a]); ++ a) {}
        if (a == n) { s = ""; return; }
        for (b = n - 1; b >= 0 && isspace(s[b]); -- b) {}
        s = s.substr(a, b - a + 1);*/
        
        n = s.length();        
        while(p < n) {
            while (isspace(s[p])) ++ p;
            a = b = p;
            while (p < n && ! isspace(s[p])) ++ p;
            b = p - 1;
            rev(s, a, b);
        }
        
        rev(s, 0, s.length() - 1);
    }
    
    bool isspace(char c) { return c == ' ' || c == '\t'; }

    void rev(string &s, int a, int b) {
        while (a < b) {
            swap(s[a ++], s[b --]);
        }
    }
    
    void removeSpace(string &s) {
        // now remove extra spaces
        char * b, * p;
        
        b = p = (char*) s.c_str();
        while (isspace(*b)) ++ b;
        
        while (1) {
            if (! *b) {
                *p = '\0';
                break;
            }
            while (*b && ! isspace(*b)) {
                *p = *b; ++ p; ++ b;
            }
            
            if (isspace(*b)) {
                while (isspace(*b)) ++ b;
                if (*b) {
                    *p = ' '; ++ p; 
                }
            }
        }
        
        s = s.c_str(); // needed! Seems for some reason "*p = '\0'" is not working.
    }    
};


void test() {
    string s = " xy z ";
    cout << "[" << s << "]" << endl;
    s[0] = '\0';
    //s = s.c_str(); // must add this for s to become empty string.
    cout << "[" << s << "]" << endl;
}

int main() {
    Solution so;
    string s = " This is blue sky "; //+---...2x+--x--+x-+-x2...---+";
    cout << "Input: \"" << s << "\"" << endl;
    so.reverseWords(s);
    cout << "Output: \"" << s << "\"" << endl;
    
    test();
    
    return 0;
}


/*
 Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

click to show clarification.
Clarification:

    What constitutes a word?
    A sequence of non-space characters constitutes a word.
    Could the input string contain leading or trailing spaces?
    Yes. However, your reversed string should not contain leading or trailing spaces.
    How about multiple spaces between two words?
    Reduce them to a single space in the reversed string.

Note: 
    it seems the removal of spaces can be a seprate task or problem.
 */
