//
// Test usage of priority queue.
// 
// @Author: Xin Chen
// @Created on: 4/10/2013
// @Last modified: 4/10/2013
//
#include <iostream>
#include <queue>
#include <list>
using namespace std;

class cmp {
public:
    bool operator()(const int a, const int b) {
        return a > b; // < or default: max heap; >: min heap
    }
};

void test1() {
    cout << "test1" << endl;
    priority_queue<int, vector<int>, cmp> pq;
    //priority_queue<int, vector<int> > pq; // This works too.
    
    int A[] = {1,3,5,7,4,2,6,4};
    int n = sizeof(A) / sizeof(int);
    for (int i = 0; i < n; ++ i) {
        pq.push(A[i]);
    }
    
    while (! pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

int main() {
    test1();
    return 0;
}
