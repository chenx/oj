/*
 * Given a dictionary and a long string, insert space(s) into the string
 * so it becomes a sentence, each word is from the dictionary.
 * http://www.mitbbs.com/article_t1/JobHunting/32174289_0_1.html
 * 
 * Method: 1) backtrack. 2) DP, O(N^2).
 * 
 * @Author: Xin Chen
 * @Created on: 1/17/2013
 * @Last modified: 4/7/2013
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class solution {
public:
           
    vector<vector<string> > addSpace(string s, vector<string> & dic) {
        vector<vector<string> > ans;
        vector<string> v;
        doAddSpace(s, dic, 0, v, ans);
        return ans;
    }
    
    bool doAddSpace(string s, vector<string> & dic, int pos, 
                    vector<string> &v, vector<vector<string> > &ans) {
        if (pos == s.length()) {
            ans.push_back(v);
            return true;
        }
        
        string word;
        for (int i = pos; i < s.length(); ++ i) {
        //for (int i = s.length() - 1; i >= pos; -- i) { // This works too.
            word = s.substr(pos, i - pos + 1);
            if ( find(dic.begin(), dic.end(), word) != dic.end()) { // if ( inDic(dic, word) ) {
                v.push_back(word);
                if (doAddSpace(s, dic, i+1, v, ans)) {
                    //return true; // this will return only 1 interpretation.
                }
                v.erase(v.end() - 1);
            }
            else { 
                // do this, if not sure there is any good combination, 
                // and wants to find a combination of best possible match.
                // In that case, when pos == s.length(), count the number of matches/un-matches.
                //doAddSpace(s, dic, i+1, v, ans); 
            }
        }
        
        return false;
    }
    
    bool inDic(vector<string> & dic, string s) {
        return find(dic.begin(), dic.end(), s) != dic.end();
        // This works too.
        //for (vector<string>::iterator it = dic.begin(); it != dic.end(); ++ it) {
        //    if (*it == s) return true;
        //}
        //return false;
        
        // This also works.
        //for (int i = 0; i < dic.size(); ++ i) {
        //    if (dic[i] == s) return true;
        //}
        //return false;
    }    
    
    //
    // O(N^2) DP algorithm, to determine if a string is a valid sentence.
    // http://www.careercup.com/question?id=3534579
    //
    bool isGood(string s, vector<string> & dic) {
        int n = s.length();
        int isValid[1+n];
        memset(isValid, 0, sizeof(int) * (1+n));
        
        isValid[0] = 1;
        
        for (int i = 0; i < n; ++ i) {
            //for (int j = i; j >= 0; -- j) {
            for (int j = 0; j <= i; ++ j) {
                if (! isValid[j]) continue;
                string w = s.substr(j, i-j+1);
                if (find(dic.begin(), dic.end(), w) != dic.end()) {
                   isValid[i+1] = 1;
                }
            }
        }
        
        return isValid[n];
    }
    
    //
    // O(N^2) DP method. Get all good combinations.
    // @Author: Xin Chen. Modified from isGood(). 4/7/2013
    //
    vector<vector<string> > getGood(string s, vector<string> & dic) {
        int n = s.length();
        vector<vector<vector<string> > > goods(1+n);
        goods[0] = vector<vector<string> >(0);
        
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j <= i; ++ j) {
                string w = s.substr(j, i-j+1);
                if (find(dic.begin(), dic.end(), w) != dic.end()) {
                   if (j == 0) { // entire string s[0..i] is a word.
                       //cout << i << ": found word: " << w << endl;
                       vector<string> v(1);
                       v[0] = w;
                       goods[i+1].push_back(v);
                   }
                   else if (goods[j].size() > 0) {
                       //cout << "i=" << i << ", j=" << j << ": found. add word: " << w  << endl;
                       for (int k = 0; k < goods[j].size(); ++ k) {
                           vector<string> v = goods[j][k];
                           v.push_back(w);
                           goods[i+1].push_back(v);
                       }
                   }
                }
            }
        }
        
        sort(goods[n].begin(), goods[n].end());
        return goods[n];
    }

    void dumpVec(vector<string> v) {
        for (int i = 0; i < v.size(); ++ i) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    
    void dumpVecVec(vector<vector<string> > ans) {
        for (int j = 0; j < ans.size(); ++ j) {
            for (int i = 0; i < ans[j].size(); ++ i) {
                cout << ans[j][i] << " ";    
            }
            cout << endl;
        }
    }
};


int main() {
    string words[] = {"this", "is", "a", "good", "nice", "day", "student", "go", "od", "ago", "odd", "ay"};
    vector<string> dic;
    for (int i = 0; i < 12; ++ i) {
        dic.push_back(words[i]);    
    }
    
    solution s;
    string str = "thisisagoodday"; // "a"
    vector<vector<string> > ans = s.addSpace(str, dic);
    s.dumpVecVec(ans);
    
    cout << "isGood = " << s.isGood(str, dic) << endl;
    
    vector<vector<string> > ans2 = s.getGood(str, dic);
    s.dumpVecVec(ans2);

    return 0;
}
