//
// Returns whether 24 can be calculated from the given array of (4) integers.
// 
// @by: X.C.
// @created on: 4/29/2016
// @last modified: 4/29/2016
//

#include <iostream>
#include <set>
#include <vector>
#include <cmath>
using namespace std;

#define DEBUG 1

string to_string(bool v) { 
    return v ? "True" : "False"; 
}

void dump(vector<double> &v) {
    for (int i = 0; i < v.size(); ++ i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void dump(vector<int> &v) {
    for (int i = 0; i < v.size(); ++ i) {
        cout << v[i] << " ";
    }
    cout << endl;
}


// Provide:
// 1) a calcK() function to calculate K.
// 2) a calc24() function to calculate 24.
// 
// In more implementation details, two methods are provided: calc() and calc2().
// calc2() is optimized from calc(), no longer creates sub vectors.
class Calc24 {
private:
    // given array v, calcuate all possible values.
    // this is optimized from calc, no longer create new sub-vectors.
    vector<double> calc2(const vector<int> & v) {
        return calc2(v, 0, v.size());
    }
    vector<double> calc2(const vector<int> & v, int left, int right) {
        set<double> ans;
        if (left >= right) return vector<double>(); // should not happen.
        if (left + 1 == right) return vector<double>(1, v[left]);

        for (int i = left + 1; i < right; ++ i) {
            vector<double> L = calc2(v, left, i);
            vector<double> R = calc2(v, i, right);

            for (int j = 0; j < L.size(); ++ j) {
                for (int k = 0; k < R.size(); ++ k) {
                    ans.insert(L[j] + R[k]);
                    ans.insert(L[j] - R[k]);
                    ans.insert(L[j] * R[k]);
                    if (R[k] != 0) ans.insert(L[j] / R[k]);
                }
            }
        }

        return vector<double>(ans.begin(), ans.end());
    }

    // given array v, calcuate all possible values.
    vector<double> calc(const vector<int> & v) {
        set<double> ans;
        int n = v.size();
        if (n == 1) return vector<double>(v.begin(), v.end());

        for (int i = 1; i < n; ++ i) {
            vector<double> L = calc(vector<int>(v.begin(), v.begin() + i));
            vector<double> R = calc(vector<int>(v.begin() + i, v.end()));

            for (int j = 0; j < L.size(); ++ j) {
                for (int k = 0; k < R.size(); ++ k) {
                    ans.insert(L[j] + R[k]);
                    ans.insert(L[j] - R[k]);
                    ans.insert(L[j] * R[k]);
                    if (R[k] != 0) ans.insert(L[j] / R[k]);
                }
            }
        }

        return vector<double>(ans.begin(), ans.end());
    }

    // return next permutation of num. O(n).
    bool nextPermutation(vector<int> &num) {
        int n = num.size();
        if (n <= 1) return false;

        int i, j;
        for (i = n - 2; i >= 0 && num[i] >= num[i + 1]; -- i) ;

        if (i < 0) return false;
        else {
            for (j = n - 1; num[j] <= num[i]; -- j) ;
            swap(num[i], num[j]);
            reverse(num.begin() + i + 1, num.end());     
            return true;
        }
    }

public:
    // If can calculate value K, return true; otherwise return false.
    // By default K = 24.
    bool calcK(vector<int> &num, int K) {
        sort(num.begin(), num.end()) ;
        do{ 
            if (DEBUG & 1) dump(num); // display input array.
            vector<double> result = calc2(num);
            if (DEBUG & 2) dump(result);  // display all possible outcome.
            for (int i = 0; i < result.size(); ++ i) {
                if (abs(result[i] - K) < 0.000001) return true;
            }
        } while (nextPermutation(num));
        return false;
    }

    bool calc24(vector<int> &num) {
        return calcK(num, 24);
    }
};


void test(vector<int> & v, bool expect) {
    Calc24 so;
    bool answer = so.calc24(v);
    cout << "expect: " << to_string(expect) << ", " 
         << "answer: " << to_string(answer) << ". ..."
         << (expect == answer ? "pass" : "fail") << endl << endl;
}

void test1() { // ((1+6)*3)+3
    vector<int> v(4);
    v[0] = 1; v[1] = 3; v[2] = 3; v[3] = 6;
    test(v, true);
}

void test2() { // ((3/7)+3)*7
    vector<int> v(4);
    v[0] = 3; v[1] = 7; v[2] = 7; v[3] = 3;
    test(v, true);
}   

void test3() { // 3/(1-(7/8))
    vector<int> v(4);
    v[0] = 1; v[1] = 3; v[2] = 8; v[3] = 7;
    test(v, true);
}

void test4() { 
    vector<int> v(4);
    v[0] = 1; v[1] = 9; v[2] = 8; v[3] = 9;
    test(v, false);
}


int main() {
    test1();
    test2();
    test3();
    test4();
    return 0;
}

