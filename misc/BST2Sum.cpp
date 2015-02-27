/**
 * Given a BST and a value K, return all pairs of nodes whose value sum is K. (GG)
 *
 * Method 1: convert BST to an array, apply the two sum algorithm. O(n) time, O(n) space.
 * Method 2: use 2 iterators from head and tail, similar to two sum. O(n) time, O(log(n)) space.
 * Method 3: assume there is a parent pointer in Node, directly get the next smallest/largest node 
 *           as in the two sum algorihtm. O(n) time, O(1) space. This is how Solution below is done.
 * 
 * Discussion: Here we assume Node has a pointer to parent to get the solution.
 * If there is no parent pointer, is a O(n) solution possible?
 * 
 * By: X.C.
 * On: 2/25/2015
 */

#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    Node * parent;
    Node * left;
    Node * right;
    Node(int v) : val(v), left(NULL), right(NULL), parent(NULL) {}
};

//
// This works for test1().
// Assume there is a parent pointer in Node, directly get the next smallest/largest node 
// as in the two sum algorihtm. O(n) time, O(1) space. 
//
class Solution {
public:
  vector<pair<Node *, Node *> > getSumNodes(Node * root, int sum) {
    vector<pair<Node *, Node *> > x;
    if (! root) return x;
    get(x, getSmallest(root), getLargest(root), sum);
    return x;
  }

private:
  void get(vector<pair<Node *, Node *> > & x, Node * L, Node * R, int sum) {
    // Note: although in a BST no 2 nodes' values are the same,
    // it's possible L and R are the same node, therefore the ">=" here.
    // E.g., BST contains only a root, then L == R == root.
    if (! L || ! R || L->val >= R->val) { return; }

    int s = L->val + R->val;
    if (s == sum) {
        x.push_back(pair<Node *, Node *>(L, R));
        get(x, getNextSmallest(L), R, sum); // add this, to get other pairs.
        // this also works: get(x, L, getNextLargest(R), sum);
    }
    else if (s < sum) {
        get(x, getNextSmallest(L), R, sum);
    }
    else { // s > sum
        get(x, L, getNextLargest(R), sum);
    }
  }

  Node * getSmallest(Node * n) {
    while (n->left) n = n->left; 
    return n;
  }

  Node * getLargest(Node * n) {
    while (n->right) n = n->right;
    return n;
  }

  /*
   p
  /
 n
  \
   m
  / \

  */
  Node * getNextSmallest(Node * n) {
    if (! n) return NULL;
    
    // n's right sub-tree is not empty.
    if (n->right) {
        Node * m = n->right;
        if (m->left == NULL) return m;
        else {
            for (m = m->left; m->left; m = m->left) ;
            return m;
        }
    }

    // n's parent is not empty.
    if (n->parent) {
        if (n == n->parent->left) return n->parent;
        else { // n == n->parent->right
            for (n = n->parent; n->parent && n == n->parent->right; n = n->parent) ;
            return n->parent; // n is parent's left child.
        }
    }
    
    return NULL;
  }

  Node * getNextLargest(Node * n) {
    if (! n) return NULL;
    if (n->left) {
        Node * m = n->left;
        if (m->right == NULL) return m;
        else {
            for (m = m->right; m->right; m = m->right) ;
            return m;
        }
    }

    // n's parent is not empty.
    if (n->parent) {
        if (n == n->parent->right) return n->parent;
        else { // n == n->parent->right
            for (n = n->parent; n->parent && n == n->parent->left; n = n->parent) ;
            return n->parent; // n is parent's left child.
        }
    }
    return NULL;
  }
};


/*
BST:
    4
   / \
  2   5
 /
1
Sum: 6
Expected return:
1, 5
2, 4
 */
void test1() {
    Node * root = new Node(4);
    root->left = new Node(2);
    root->left->parent = root;
    root->right = new Node(5);
    root->right->parent = root;

    root->left->left = new Node(1);
    root->left->left->parent = root->left;

    Solution so;
    vector<pair<Node *, Node *> > x = so.getSumNodes(root, 6);

    for (int i = 0; i < x.size(); ++ i) {
        cout << x[i].first->val << ", " << x[i].second->val << endl;
    }
}

int main() {
    test1();
    return 0;
}
