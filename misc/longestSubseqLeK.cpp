//
// Given an int array, find the longest subarray whose averge <= k.
//

#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

void dump(vector<int> v) {
    for (int i = 0; i < v.size(); ++ i) cout << v[i] << " ";
    cout << endl;
}

vector<int> longestSubseqLek(vector<int> v, int k) {
    vector<int> ans(2);
    
    int len = v.size();
    for (int i = 0; i < len; ++ i) v[i] -= k;
    
    vector<int> S(len+1);
    S[0] = 0;
    for (int i = 0; i < len; ++ i) { S[i+1] = S[i] + v[i]; }
    
    stack<pair<int, int> > st;
    
    int smallest = INT_MAX;
    for (int i = len; i > 0; ++ i) {
        if (S[i] < smallest) {
            st.push(pair<int, int>(S[i], i-1));
            smallest = S[i];
        }
    }
    
    int current = INT_MIN;
    for (int i = 0; i < len; ++ i) {
        if (S[i+1] > current) {
            pair<int, int> p = st.top();
            if (p.first - S[i] <= 0) {
                if (p.second - i >= ans
                ans[0] = 
            }
            current = S[i+1];
        }
    }
    
    return ans;
}

int main() {
    int a[] = {3,4,2,1,5,7,9,8,4,3,4};
    vector<int> v(a, a + sizeof(a) / sizeof(int));
    dump(v);
    const int k = 4;
    
    vector<int> ans = longestSubseqLek(v, k);
    
    dump(ans);
    
    return 0;
}
