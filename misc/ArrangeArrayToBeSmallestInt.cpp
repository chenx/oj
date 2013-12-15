//
// Baidu interview Q 2009: 
// Arrange an array of integers, such that the integer formed by 
// concatenating all numbers in the array in order is the smallest.
//
// Idea: sort the array first, then combine.
// Rule of compare: see function comp() below.
//
// @Created on: 3/9/2013
// 
#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool comp(int n1, int n2) {
    char a1[10], a2[10];
    sprintf(a1, "%d", n1);
    sprintf(a2, "%d", n2);
    string s1 = a1;
    string s2 = a2;
    //cout << s1 << "," << s2 << endl;
    //cout << (s1+s2) << " < " << (s2+s1) << ": " << (s1 + s2 < s2 + s1) << endl;
    return s1 + s2 < s2 + s1;
}

void dump(vector<int> &a) {
    for (int i = 0; i < a.size(); ++ i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void test() {
    int arr[] = {32, 332, 321, 32};
    int len = sizeof(arr) / sizeof(int);
    vector<int> a;
    for (int i = 0; i < len; ++ i) { a.push_back(arr[i]); }
    cout << "before sort: "; dump(a);
    sort(a.begin(), a.end(), comp);
    cout << "after  sort: "; dump(a);
    
    for (int i = 0; i < a.size(); ++ i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    test();
    return 0;
}
