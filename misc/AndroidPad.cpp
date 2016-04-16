/**
 * Given an Android unlock screen, get all possible unlock patterns of
 * length 4 to 9. Solution is given by DFS.
 *
 * By: X.C. 4/15/2016
 */

#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;


class Solution {
public:
    map<int, set<string> > getComb() {
        map<int, set<string> > ans;

        vector<vector<char> > pad(3, vector<char>(3));
        for (int i = 0; i < 9; ++ i)
            pad[i/3][i%3] = '1' + i;

        for (int i = 0; i < 3; ++ i)
            for (int j = 0; j < 3; ++ j)
                get(ans, pad, "", i, j);

        return ans;
    }

    void get(map<int, set<string> > & ans, vector<vector<char> > & pad, string p, int i, int j) {
        char c = pad[i][j];
        p += c;
        pad[i][j] = 'a' + p.length() - 1; // abcdefghi labels the visit order.
        //pad[i][j] = '.';
        //drawPad(pad);

        int n = p.length();
        if (n >= 4) {
            ans[n].insert(p);
        }

        if (n < 9) {
            for (int k = 0; k < dirs.size(); ++ k) {
                int x = i + dirs[k].first, y = j + dirs[k].second;

                if (x >= 0 && x < 3 && y >= 0 && y < 3) {
                    if (isdigit(pad[x][y]))  // if (pad[x][y] != '.') {
                        get(ans, pad, p, x, y);
                }
            }
        }

        pad[i][j] = c; // recover value of pad[i][j] for backtracking.
    }

    vector<pair<int, int> > dirs;

    Solution() {
        dirs.push_back(pair<int, int>(-1,-1));
        dirs.push_back(pair<int, int>( 0,-1));
        dirs.push_back(pair<int, int>( 1,-1));
        dirs.push_back(pair<int, int>(-1, 0));
        dirs.push_back(pair<int, int>( 1, 0));
        dirs.push_back(pair<int, int>(-1, 1));
        dirs.push_back(pair<int, int>( 0, 1));
        dirs.push_back(pair<int, int>( 1, 1));
    }

    void drawPad(vector<vector<char> > & pad) {
        for (int i = 0; i < 3; ++ i) {
            for (int j = 0; j < 3; ++ j) {
                cout << pad[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};


void dump(int len, set<string> & s) {
    cout << "len: " << len << ", size: " << s.size() << endl;
    return; //
    for (set<string>::iterator it = s.begin(); it != s.end(); ++ it) {
        cout << *it << " ";
    }
    cout << endl;
}


void test1() {
    Solution so;

    map<int, set<string> > v = so.getComb();

    for (map<int, set<string> >::iterator it = v.begin(); it != v.end(); ++ it) {
        dump(it->first, it->second);
    }
}

int main() {
    test1();
    return 0;
}


/**
Output:

len: 4, size: 496
len: 5, size: 1208
len: 6, size: 2240
len: 7, size: 2984
len: 8, size: 2384
len: 9, size: 784
 */
        
