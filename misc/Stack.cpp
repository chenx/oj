//
// To review Stack operations.
//
// @Author: Xin Chen
// @Created on: 4/7/2013
// @Last modified: 4/7/2013
// 
#include <iostream>
using namespace std;


class Node {
public:
    int val;
    Node * next;
    Node(int v) : val(v), next(NULL) {}
};

// return new top.
Node * push(Node * top, int v) {
    if (! top) {
        return new Node(v);
    }
    
    Node * n = new Node(v);
    n->next = top;
    return n;
}

Node * top(Node * top) {
    return top;
}

void pop(Node *& top) {
    if (! top) return;
    
    Node * tmp = top;
    top = top->next;
    delete tmp;
}

int main() {
    return 0;
}
