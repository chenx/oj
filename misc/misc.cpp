//
// random stuff.
//
#include <iostream>
#include <queue>
#include <list>
using namespace std;


void test1() {
    cout << "test1" << endl;

    const int n = 5;
    int A[n][n] = {0};
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << endl;
}

int main() {
    test1();
    return 0;
}
