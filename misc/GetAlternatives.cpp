// Say 3 items coke, fries, ham have the same prices $2,
// given (2, 2, 2), return all possible alternative 
// combinations of items.
// By: X.C. 4/13/2016. Enlightened by Ub intv.

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    // Iterative.
    vector<vector<string> > getComb(vector<string> & items, int k) {
        vector<vector<string> > ans;
        int n = items.size();

        if (k <= 0) return ans;

        for (int i = 0; i < n; ++ i) {
            ans.push_back(vector<string>(1, items[i]));
        }

        for (int i = 2; i <= k; ++ i) {
            vector<vector<string> > tmp;

            for (int j = 0; j < n; ++ j) {
                // find first entry in ans that starts with items[j],
                // then add items[j] to every entry in ans since
                // this point on, and add to next round (tmp).
                int m = 0;
                while (ans[m][0] != items[j]) ++ m;

                for (; m < ans.size(); ++ m) {
                    vector<string> u = ans[m];
                    u.insert(u.begin(), items[j]);
                    tmp.push_back(u);
                }
            }
            ans = tmp;
        }

        return ans;
    }

    // Recursive.
    // Form a list of length n, choosing items.
    vector<vector<string> > getComb2(vector<string> & items, int n) {
        vector<vector<string> > ans;

        if (n == 0) {
            ans.push_back(vector<string>(1, ""));
            return ans;
        }
        if (n == 1) {
            for (int i = 0; i < items.size(); ++ i) {
                vector<string> v(1, items[i]);
                ans.push_back(v);
            }
            return ans;
        }

        vector<vector<string> > tmp = getComb(items, n - 1);
        for (int i = 0; i < tmp.size(); ++ i) {
            for (int j = 0; j < items.size(); ++ j) {
                if (le(tmp[i].back(), items[j])) {
                  ans.push_back(tmp[i]);
                  ans.back().push_back(items[j]);
                }
            }
        }

        return ans;
    }

    int le(string & a, string & b) {
        return a <= b;
    }
};


void dump(vector<string> & v) {
    cout << "[";
    for (int i = 0; i < v.size(); ++ i) {
        if (i > 0) cout << ", ";
        cout << v[i];
    }
    cout << "]";
}

void dump(vector<vector<string> > & v) {
    cout << "[";
    for (int i = 0; i < v.size(); ++ i) {
        if (i > 0) cout << ", ";
        dump(v[i]);
    }
    cout << "]" << endl;
}

void test1() {
    vector<string> items;
    items.push_back("coke");
    items.push_back("fried");
    items.push_back("ham");
    int k = 3;

    cout << "input: ";
    dump(items);
    cout << ". k = " << k << endl;

    Solution so;
    vector<vector<string> > v = so.getComb(items, k);
    cout << "iterative: "; dump(v);

    vector<vector<string> > v2 = so.getComb2(items, k);
    cout << "recursive: "; dump(v2);
}

int main() {
    test1();
    return 0;
}


/**
 Example output:
 
 input: [coke, fried]. k = 3
 [[coke, coke, coke], [coke, coke, fried], [coke, fried, fried], [fried, fried, fried]]
 [[coke, coke, coke], [coke, coke, fried], [coke, fried, fried], [fried, fried, fried]]


 input: [coke, fried, ham]. k = 3
 iterative: [[coke, coke, coke], [coke, coke, fried], [coke, coke, ham], [coke, fried, fried], 
            [coke, fried, ham], [coke, ham, ham], [fried, fried, fried], [fried, fried, ham], 
            [fried, ham, ham], [ham, ham, ham]]
 recursive: [[coke, coke, coke], [coke, coke, fried], [coke, coke, ham], [coke, fried, fried], 
            [coke, fried, ham], [coke, ham, ham], [fried, fried, fried], [fried, fried, ham], 
            [fried, ham, ham], [ham, ham, ham]]
 */
