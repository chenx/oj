//
// Same as NextPermutation, just change the two conditions on num[] in the 2 for loops.
// By: X.C. 4/18/2016
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool prevPermutation(vector<int> &num) {
        int n = num.size();
        
        int i, j;
        for (i = n-2; i >= 0 && num[i] <= num[i+1]; -- i) {} // find first num[i] > num[i+1]. // >= -> <=
        
        if (i == -1) {
            reverse(num.begin(), num.end());
            return false;
        }
        
        for (j = n-1; num[j] >= num[i]; -- j) {} // find first elem from right smaller than num[i]. // <= -> >=
        swap(num[i], num[j]);
        
        reverse(num.begin() + i + 1, num.end());
        return true;
    }
};


void dump(vector<int> & v) {
    for (int i = 0; i < v.size(); ++ i)
        cout << v[i] << " ";
    cout << endl;
}

void test1() {
    vector<int> v;
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);

    Solution so;

    do {
        dump(v);
    } while (so.prevPermutation(v));
}

int main() {
    test1();
    return 0;
}


/**
output:
3 2 1 
3 1 2 
2 3 1 
2 1 3 
1 3 2 
1 2 3 
 */
