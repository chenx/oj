/**
 * This program calculates 24 from 4 given numbers.
 *
 * Note that by pure brutal force, 4 numbers have 4! permutations, for each
 * there are 3 places to insert 4 operators each. Then to parenthesize them
 * there are catalan number of ways (2n)!/(n! * (n+1)!). 
 * That's n! * (n-1) * n! * (2n)!/(n! * (n+1)!), where n = 4. 
 * This is 24192 ways. The code here reduces the numbers of combinations,
 * by separate the 4 numbers into 2 groups each time, in each group 
 * duplicates are combined. E.g., (1+1), (1*1), (1/1) all result in 1,
 * and the 3 cases are combined into 1 case.
 * For implementation, see function: calc2(vector<int> v, int level)
 * 
 * Possible improvement:
 * - Now cases like these are repeatedly counted:
 *   (4*(2*(3*1))), ((4*2)*(3*1)), (4*(2*3)*1), ...
 *   it might be good to unify such combinations into 1*2*3*4.
 *   (or maybe not necessary, this may be just fine.)
 *
 * @author: X. Chen
 * @Created on: 3/22/2016
 * @Last modified: 3/22/2016
 */

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <sstream>
using namespace std;

void dumpVec(vector<int> v) {
    for (int i = 0; i < v.size(); ++ i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void dumpMap(map<int, vector<string> > m, int target) {

    if (target == INT_MAX) cout << "all results: " << endl;
    else cout << "results equal to " << target << ":" << endl;

    for (map<int, vector<string> >::iterator i = m.begin(); i != m.end(); ++ i) {
        int v = (*i).first;
        if (target != INT_MAX && v != target) continue;

        if (target == INT_MAX) cout << v << " " << endl;
        vector<string> & str = (*i).second;
        for (int j = 0; j < str.size(); ++ j) {
            cout << "  (" << (1 + j) << "): " << str[j] << endl;
        }
    }
    cout << endl;
}

int stoi(string s) {
    stringstream ss(s);
    int v;
    ss >> v;
    return v;
}

string to_string(int v) {
    stringstream ss;
    ss << v;
    return ss.str();
}


class Permutation {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end()) ;
        vector<vector<int> > ret;
        do{
            ret.push_back( num );
        } while (nextPermutation(num));
        return ret;
    }

private:
    bool nextPermutation(vector<int> &num) {
        int n = num.size();
        if (n <= 1) return false;

        int i, j;
        for (i = n - 2; i >= 0 && num[i] >= num[i + 1]; -- i) ;

        if (i < 0) { // last permutation already. Go to the first permutation.
            return false;
            //sort(num.begin(), num.end()); // or reverse(num.begin(), num.end());
        }
        else {
            // get the minimal number x > num[pos] from rhs of x.
            // since the rhs of x is sorted DESC, the first x > num[pos] will do.
            // Note: '<=' is needed when duplicated elements exist, '<' not enough.
            for (j = n - 1; num[j] <= num[i]; -- j) ;
            swap(num[i], num[j]);

            // sort rhs of pos in INC order.
            reverse(num.begin() + i + 1, num.end());     // or reverse.
            return true;
        }
    }
};



class Solution {
public:
    Solution() { }

    /**
     * Given a vector of integers, get all permutations, 
     * and find ways to calcuate k = 24 for each.
     * 
     * Note that by altering the value of k, you can calculate other numbers.
     */
    void calc24(vector<int> v) {
        Permutation perm;
        vector<vector<int> > vs = perm.permuteUnique(v);
        for (int i = 0; i < vs.size(); ++ i) {
            vector<int> & in = vs[i];

            cout << "input: "; dumpVec(in);
            //cout << "all possible results: " << endl;
            //dumpVec(calc(in));

            int k = 24;
            //cout << "results equal to " << k << ": " << endl;
            map<int, vector<string> > m = calc2(in);
            dumpMap(m, k);
        }
    }

    map<int, vector<string> > calc2(vector<int> v) {
        return calc2(v, 0);
    }

    /**
     * This function takes in a vector of integers, and output all possible
     * results that can be obtained using the numbers and operators +, - , *, /.
     *
     * The input vector is actually not restricted by size, although for the poker
     * game of calculating 24 it needs to contain exactly 4 numbers.
     *
     * Input:
     *   @v - input vector.
     *   @level: used for pretty print.
     * Output:
     *   All results that can be obtained, plus the way to obtain them.
     */
    map<int, vector<string> > calc2(vector<int> v, int level) {
        map<int, vector<string> > m;
        int n = v.size();

        //cout << "in (level=" << level << "): " << string(level * 2, ' '); dumpVec(v);

        if (n == 0) return map<int, vector<string> >();
        if (n == 1) {
            m[v[0]].push_back(to_string(v[0]));
            return m;
        }

        for (int k = 1; k < n; ++ k) {
            map<int, vector<string> > LM = calc2(vector<int>(v.begin(), v.begin() + k), level + 1);
            map<int, vector<string> > RM = calc2(vector<int>(v.begin() + k, v.end()), level + 1);

            for (map<int, vector<string> >::iterator i = LM.begin(); i != LM.end(); ++ i) {
                for (map<int, vector<string> >::iterator j = RM.begin(); j != RM.end(); ++ j) {

                    int n1 = (*i).first, n2 = (*j).first;
                    vector<string> v1 = (*i).second, v2 = (*j).second;

                    getComb(m, v1, v2, n1 + n2, "+");
                    getComb(m, v1, v2, n1 - n2, "-");
                    getComb(m, v1, v2, n1 * n2, "*");

                    // Note: only consider cases where n2 divides n1 evenly with no remainder.
                    // So 3/6 is not considered. However, since all permutations are searched,
                    // it will find a case to use 6/3. Thus this covers all possibilities, and
                    // float number calculation is avoided.

                    if (n2 != 0 && (n1 % n2 == 0)) getComb(m, v1, v2, n1 / n2, "/");
                }
            }
        }

        return m;
    }

    void getComb(map<int, vector<string> > & m,
                    vector<string> & v1, vector<string> & v2, int val, string op) {
        for (int p = 0; p < v1.size(); ++ p) {
            for (int q = 0; q < v2.size(); ++ q) {
                m[val].push_back("(" + v1[p] + op + v2[q] + ")");
            }
        }

    }

    vector<int> calc(vector<int> v) {
        return calc(v, 0);
    }

    /**
     * This function only calculates all possible results, 
     * but does not show how they are obtained.
     */
    vector<int> calc(vector<int> v, int level) {
        set<int> ans;
        int n = v.size();

        //cout << "in (level=" << level << "): " << string(level * 2, ' '); dumpVec(v);

        if (n == 0) return vector<int>();
        if (n == 1) return v;

        for (int i = 1; i < n; ++ i) {
            vector<int> L = vector<int>(v.begin(), v.begin() + i);
            L = calc(L, level + 1);
            vector<int> R = vector<int>(v.begin() + i, v.end());
            R = calc(R, level + 1);

            for (int j = 0; j < L.size(); ++ j) {
                for (int k = 0; k < R.size(); ++ k) {
                    ans.insert(L[j] + R[k]);
                    ans.insert(L[j] - R[k]);
                    ans.insert(L[j] * R[k]);
                    if (R[k] != 0 && (L[j] % R[k] == 0)) ans.insert(L[j] / R[k]);
                }
            }
        }

        return vector<int>(ans.begin(), ans.end());
    }
};


int main(int argc, char * argv[]) {
    if (argc != 5) {
        cout << "To calculate 24, please enter 4 numbers as argument." << endl;
        return 0;
    }

    vector<int> in(4);

    for (int i = 1; i < argc; ++ i) {
        in[i-1] = stoi(argv[i]);
        //cout << i << ": " << argv[i] << " = " << in[i-1] << endl;
    }

    Solution so;

    if (0) { // for debug use.
        cout << "input: "; dumpVec(in);
        cout << "output: " << endl;
        dumpVec(so.calc(in));
        
        cout << "output(2): " << endl;
        map<int, vector<string> > m = so.calc2(in);
        dumpMap(m, 24);
    }

    so.calc24(in);

    return 0;
}


/**
Example. Input: 6 3 3 1. Output:

input: 1 3 3 6 
results equal to 24:

input: 1 3 6 3 
results equal to 24:

input: 1 6 3 3 
results equal to 24:
  (1): (((1+6)*3)+3)

input: 3 1 3 6 
results equal to 24:

input: 3 1 6 3 
results equal to 24:
  (1): (3+((1+6)*3))
  (2): ((3-(1-6))*3)
  (3): (((3-1)+6)*3)
  (4): ((3*(1+6))+3)

input: 3 3 1 6 
results equal to 24:
  (1): (3*(3-(1-6)))
  (2): (3*((3-1)+6))
  (3): (3+(3*(1+6)))

input: 3 3 6 1 
results equal to 24:
  (1): (3*(3+(6-1)))
  (2): (3*((3+6)-1))
  (3): (3+(3*(6+1)))

input: 3 6 1 3 
results equal to 24:
  (1): (3*(6-(1-3)))
  (2): (3*((6-1)+3))
  (3): (3+((6+1)*3))
  (4): ((3+(6-1))*3)
  (5): (((3+6)-1)*3)
  (6): ((3*(6+1))+3)

input: 3 6 3 1 
results equal to 24:
  (1): (3*(6+(3-1)))
  (2): (3*((6+3)-1))

input: 6 1 3 3 
results equal to 24:
  (1): ((6-(1-3))*3)
  (2): (((6-1)+3)*3)
  (3): (((6+1)*3)+3)

input: 6 3 1 3 
results equal to 24:
  (1): ((6+(3-1))*3)
  (2): (((6+3)-1)*3)

input: 6 3 3 1 
results equal to 24:

 */
