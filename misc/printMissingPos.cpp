/*
 * Google question: Print missing positions.
 * Two strings a and b, b is a with a few missing letters.
 * Print the positions that b misses from a.
 * E.g.:
 * "abc", "ab" => print "2"
 * "abc", "b"  => print "0 2"
 * "abc", "ac" => print "1"
 * "aab", "ab" => print "0" or "1"
 *
 * Method: backtracking.
 * 
 * @Author: Xin Chen
 * @On: 1/17/2013
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void mp (string a, string b, int pa, int pb, vector<int> v, vector<vector<int> > &ans) {
        if (pa == a.length() && pb == b.length()) { // end, match found.
            ans.push_back(v);
            return;
        }
        else if (pa == a.length()) { // no match. end.
            return;
        }
        else if (pb == b.length()) { // add last missing chars. NOTE THIS!
            while (pa < a.length()) v.push_back(pa ++); // Note: pa++, not ++pa.
            ans.push_back(v);
            return;     
        }
        
        if (a[pa] != b[pb]) {
            v.push_back(pa);
            mp(a, b, pa+1, pb, v, ans); // no match on this char.
        }
        else {
            mp(a, b, pa+1, pb+1, v, ans); // match this char.
            // assume no match on this char.
            v.push_back(pa);
            mp(a, b, pa+1, pb, v, ans);
        }        
    }
    
    vector<vector<int> > printMissingPos(string a, string b) {
        vector<vector<int> > ans;
        vector<int> v;
        mp(a, b, 0, 0, v, ans);        
        return ans;
    }
    
    void test(string a, string b) {
         puts("ans:");
         vector<vector<int> > ans = printMissingPos(a, b);
         for (int i = 0; i < ans.size(); ++ i) {
             vector<int> v = ans[i];
             for (int j = 0; j < v.size(); ++ j) {
                 printf("%d ", v[j]);
             }
             puts("");
         }
    }
};
 
int main() {
    Solution s;
    s.test("abc", "ab"); 
    s.test("abc", "b");
    s.test("abc", "ac");
    s.test("aab", "ab");    
    return 0;
}
