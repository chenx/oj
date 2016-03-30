// CCI 3.6. Page 215.
// Sort a stack, using at most one more stack.
#include <iostream>
#include <stack>
using namespace std;

void dumpStack(stack<int> s) {
    while (! s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

class Solution {
public:
    stack<int> sortStack(stack<int> & s) {
        stack<int> r;
        while (! s.empty()) {
            int v = s.top();
            s.pop();
            while (! r.empty() && r.top() < v) {
                s.push(r.top());
                r.pop();
            }
            r.push(v);
        }
        return r;
    }
};

int main() {
    int in[] = {3,2,5,4,1,8,7,9,10,6,4};
    stack<int> sin;

    for (int i = 0, len = sizeof(in) / sizeof(int); i < len; ++ i) {
        sin.push(in[i]);
    }
    Solution so;

    cout << "in:  "; dumpStack(sin);
    stack<int> sout = so.sortStack(sin);
    cout << "out: "; dumpStack(sout);

    return 0;
}
