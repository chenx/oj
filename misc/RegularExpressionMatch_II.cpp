/*
 * Another regular expression match problem.
 * 
 * @By: X. Chen
 * @Created on: 3/23/2016
 * @Last modified: 3/23/2016
 */
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

// Twitter match.
// http://www.mitbbs.com/mitbbs_article_t.php?board=JobHunting&gid=33163293&ftype=0
//
//  Text: a-z, A-Z, 0-9
//  Pattern: a-z, A-z, 0-9, +, *
//  + = 1 or more times
//  * = 0 or more times.
//
//  Pattern: a+b
//  Text: aab, ab return true
//
//  Pattern: a+b*
//  Text: aab, aa  return true
class Solution_Twitter {
public:
    bool isMatch(string s, string p) {
        return match(s.c_str(), p.c_str());
    }

    bool match(const char * s, const char * p) {
        if (! *p) return ! *s;

        if (*(p + 1) == '*') {
            // match(s+1, p) - match next char in s.
            // match(s, p+2) - match nothing in s.
            if (*p == *s) return match(s+1, p) || match(s, p+2);
            else return match(s, p+2); // match nothing in s.
        }
        else if (*(p + 1) == '+') {
            // match(s+1, p) - match next char in s.
            // match(s+1, p+2) - match exactly 1 char in s.
            if (*p == *s) return match(s+1, p) || match(s+1, p+2);
            else return false;
        }
        else if (*p == *s) {
            return match(s+1, p+1); // match exactly 1 char in s.
        }
        else {
            return false;
        }
    }
};


//
// Note: .* matches ab, because .* means 0 or more of ".", so it can be .., this matches ab.
//
class Solution {
    const char * s0, * p0;
public:
    bool isMatch(string s, string p) {
        s0 = s.c_str(), p0 = p.c_str();
        return match(s.c_str(), p.c_str(), 1);
    }

    string to_string(int v) {
        stringstream ss;
        ss << v;
        return ss.str();
    }

    string pr(int ct) {
        return string(ct, ' ') + to_string(ct);
    }

    bool match(const char * s, const char * p, int ct) {
        cout << pr(ct) << ": enter match(" << (s - s0) << ", " << (p - p0) << ")" << endl;
        if (! *p) {
            cout << pr(ct) << ": ! *p. ! *s = " << (! *s) << endl;
            return ! *s;
        }

        if (*(p+1) == '*') {
            //cout << pr(ct) << ": *p = " << *p << endl;
            if ( (*s && *p == '.') || *s == *p) {
                cout << pr(ct) << ": check s+1, p" << endl;
                if (match(s+1, p, ct+1)) { return true; }

                cout << pr(ct) << ": check s, p+2" << endl;
                if (match(s, p+2, ct+1)) { return true; }

                cout << pr(ct) << ": no match, fail" << endl;
                return false;
            }
            else {
                cout << pr(ct) << ": p+2(2)" << endl;
                return match(s, p+2, ct+1);
            }
        }
        else if ( (*s && *p == '.') || *s == *p) {
            cout << pr(ct) << ": s+1, p+1" << endl;
            return match(s+1, p+1, ct+1);
        }
        else {
            return false;
        }
    }
};


void test_Solution() {
    vector<pair<string, string> > tests;
    //tests.push_back(pair<string, string>("abc", "a.."));
    tests.push_back(pair<string, string>("ab", ".*"));

    Solution so;
    for (int i = 0; i < tests.size(); ++ i) {
        string s = tests[i].first, p = tests[i].second;
        cout << "isMatch(" << s << ", " << p << "): " << endl;
        cout << (so.isMatch(s, p) ? "True" : "False") << endl << endl;
    }
};

void test_Solution_Twitter() {
    vector<pair<string, string> > tests;
    //tests.push_back(pair<string, string>("abc", "a.."));
    tests.push_back(pair<string, string>("aab", "a+b"));
    tests.push_back(pair<string, string>("ab", "a+b"));
    tests.push_back(pair<string, string>("aab", "a+b*"));
    tests.push_back(pair<string, string>("aa", "a+b*"));

    Solution_Twitter so;
    for (int i = 0; i < tests.size(); ++ i) {
        string s = tests[i].first, p = tests[i].second;
        cout << "isMatch(" << s << ", " << p << "): " << endl;
        cout << (so.isMatch(s, p) ? "True" : "False") << endl << endl;
    }
};


int main() {
    cout << "hi " << endl;

    test_Solution();
    test_Solution_Twitter();

    return 0;
}


/**
Output:

isMatch(ab, .*): 
 1: enter match(0, 0)
 1: check s+1, p
  2: enter match(1, 0)
  2: check s+1, p
   3: enter match(2, 0)
   3: p+2(2)
    4: enter match(2, 2)
    4: ! *p. ! *s = 1
True

isMatch(aab, a+b): 
True

isMatch(ab, a+b): 
True

isMatch(aab, a+b*): 
True

isMatch(aa, a+b*): 
True
 */
