/**
 * Printing a Binary Tree top-down (column wise).
 *
 * E.g. binary tree:
 *    1
 *  2   3
 * 4 5 6 7
 * print: 124, 125, 136, 137.
 *
 * By: X.C.
 * On: 2/6/2015
 */
 
#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int val;
    Node * left;
    Node * right;
    Node(int v): val(v), left(NULL), right(NULL) {}
};


void output(stack<int> s) {
    if (s.empty()) return;
    int tmp = s.top();
    s.pop();
    output(s);
    cout << tmp << " ";
}

// This works. But iterative version seems not easy.
void printT(Node * n, stack<int> & s) {
    if (n == NULL) return;

    s.push(n->val);

    if (n->left == NULL && n->right == NULL) {
        output(s);
        cout << endl;
    } else {
        printT(n->left, s);
        printT(n->right, s);
    }

    s.pop();
}

int main() {
    Node * root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    stack<int> s;
    printT(root, s);
    return 0;
}

