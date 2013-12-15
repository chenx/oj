#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;


class WW {
public:
    string w;
    WW * prev;
    WW(string _w, WW * p) : w(_w), prev(p) { }
};


class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string>> ans;
        queue<WW *> words;
        set<string> words_used;
        int min_len = 0;
        
        words.push(new WW(start, NULL));
        words_used.insert(start);
        
        while (words.size() > 0) {
            WW * z = words.front();
            words.pop();
            string w = z->w;
            
            int len = w.length();
            for (int i = 0; i < len; ++ i) {
                char c = w[i];
                for (int j = 0; j < 26; ++ j) {
                    if (c == 'a' + j) continue;
                    
                    w[i] = 'a' + j;
                    if (w == end) {
                        vector<string> a;
                        a.insert(a.begin(), end);

                        for (WW * x = z; x->prev; x = x->prev) {
                            a.insert(a.begin(), x->w);
                        }
                        a.insert(a.begin(), start);
                        
                        if (min_len == 0) {
                            ans.push_back(a);
                            min_len = a.size();
                        } else if (min_len == a.size()) {
                            ans.push_back(a);
                        } else if (min_len > a.size()) {
                            ans.clear();
                            ans.push_back(a);
                            min_len = a.size();
                        }
                    }
                    else {
                        if (dict.find(w) != dict.end() 
                            && words_used.find(w) == words_used.end() ) {
                            words.push(new WW(w, z));
                            words_used.insert(w);
                        }
                    }
                    
                } // end of for
                w[i] = c;
            } // end of for
        }
        
        return ans; //min_len;
    }

};

void test1() {
    string start = "hot", end = "dog";
    unordered_set<string> s;
    string dic[] = {"hot","cog","dog","tot","hog","hop","pot","dot"};
    for (int i = 0; i < dic.size(); ++ i) {
        s.insert(dic[i]);
    }
    Solution so;
    vector<vector<string> > ans = so.findLadders(start, end, s);
    for (int i = 0; i < ans.size(); ++ i) {
        vector<string> a = ans[i];
        for (int j = 0; j < a.size(); ++ j) {
            cout << a[j] << " ";
        }
        cout << endl;
    }
    
}

int main() {
    test1();
    return 0;
}
