//
// Implementation of the KMP string matching algorithm.
// Knuth-Morris-Pratt. Running time: O(n+m).
// Pre-process pattern string. Avoid throwing away previous information.
// Reference:
// Data Structure And Algorithms in Java. M. Goodrich, R. Tamassia. p.448.
// X. C. 1/20/2015
//

#include <iostream>
#include <vector>
using namespace std;

void dump_vec(vector<int> & v) {
    cout << "vec size = " << v.size() << endl;
    for (int i = 0; i < v.size(); ++ i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void getFailureFunc(string P, vector<int> & F) {
    int m = P.length();
    int i = 1, j = 0;
    F[0] = 0;
    
    while (i < m) {
        //cout << "i = " << i << ", m = " << m << endl;
        if (P[i] == P[j]) {
            F[i] = j + 1;
            ++ i, ++ j;
        }
        else if (j > 0) {
            j = F[j - 1];
        }
        else {
            F[i] = 0;
            ++ i;
        }
    }
    dump_vec(F);
}

int kmpMatch(string T, string P) {
    int n = T.length(), m = P.length();
    if (n < m) return -1; // text is shorter than pattern.
    if (m == 0) return 0; // pattern is empty string.
    
    vector<int> F(m);
    getFailureFunc(P, F); //return -1;
    int i = 0, j = 0;
    
    while (i < n) {
        if (T[i] == P[j]) {
            if (j == m-1) {
                return i -m + 1;
            }
            ++ i, ++ j;
        }
        else if (j > 0) {
            j = F[j - 1];
        }
        else { // j == 0
             ++ i;
        }
    }
    return -1;
}

int main() {
    string T = "abacaabacabdd", P = "abacab";
    int k = kmpMatch(T, P);
    cout << "k = " << k << endl;
    return 0;
}
