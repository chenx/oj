//
// Reverse a stack using recursion only.
// http://zhedahht.blog.163.com/blog/static/25411174200943182411790/
// 
// @Created on: 3/9/2013
//

#include <stack>
#include <iostream>
using namespace std;

void putToBottom(stack<int> &s, int n) {
    if (s.empty()) {
        s.push(n);
        return;
    }
    int t = s.top();
    s.pop();
    putToBottom(s, n);
    s.push(t);
}

void RevStack(stack<int> &s) {
    if (s.empty()) return;
    int n = s.top();
    s.pop();
    RevStack(s);
    putToBottom(s, n);
}

void dumpStack(stack<int> s) {
    while (! s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    
    dumpStack(s);
    RevStack(s);
    dumpStack(s);
    
    return 0;
}
