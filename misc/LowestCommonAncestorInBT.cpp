// 
// Find the lowest common ancestor of two given nodes in a given binary tree.
// The method here is given by wang ya.
// Another method is at: http://zhedahht.blog.163.com/blog/static/25411174201081263815813/
// it seems much more complex.
//
// @By: wang ya
// @Created on: 3/9/2013
//
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Node {
public:
    int val;
    Node * parent;
    Node * left;
    Node * right;
    Node(int v) : val(v), parent(NULL), left(NULL), right(NULL) {}
};


Node *LCA(Node *root, Node *p, Node *q) {
  if (!root) return NULL;
  if (root == p || root == q) return root;
  Node *L = LCA(root->left, p, q);
  Node *R = LCA(root->right, p, q);
  if (L && R) return root;
  return L ? L : R;
}


//
// Print All common ancestors of 2 nodes in a BST in O(n) time, O(1) space.
//
Node *LCA_path(Node *root, Node *p, Node *q) {
  if (!root) return NULL;
  if (root == p || root == q) return root;
  Node *L = LCA_path(root->left, p, q);
  Node *R = LCA_path(root->right, p, q);
  if (L && R) {
      cout << root->val << endl;
      return root;
  }

  // if L or R is not NULL, and is not p or q, then yes.  
  Node * n = L ? L : R;
  if (n && n != p && n != q) cout << root->val << endl;
  
  return L ? L : R;
}


//
// Lowest common ancestor of a binary tree II
// Give a binary tree, find the lowest common ancestor of two given nodes in 
// the tree. Each node contains a parent pointer which links to its parent.
// 	Follow up: Could you eliminate the need of extra space?
//

// Code 51 LCA II, Using extra space (set)
Node *LCA(Node *p, Node *q) {
  //hash_set<Node *> visited;
  set<Node *> visited;
  while (p || q) {
    if (p) {
      if (!visited.insert(p).second) return p;
      p = p->parent;
    }
    if (q) {
      if (!visited.insert(q).second) return q;
      q = q->parent;
    }
  }
  return NULL;
}

int getHeight(Node *p) {
    int height = 0;
  while (p) {
    height++;
    p = p->parent;
  }
  return height;
} 

// Code 51 LCA II, NOT Using extra space (set)
Node *LCA2(Node *p, Node *q) {
  int h1 = getHeight(p);
  int h2 = getHeight(q);
    if (h1 > h2) {
    swap(h1, h2);
    swap(p, q);
  }
  
  int dh = h2 - h1;
  for (int h = 0; h < dh; h++)
    q = q->parent;
  while (p && q) {
    if (p == q) return p;
    p = p->parent;
    q = q->parent;
  }
  return NULL;
}


int main() {
    Node * n1 = new Node(1);
    Node * n2 = new Node(2);
    Node * n3 = new Node(3);
    Node * n4 = new Node(4);
    Node * n5 = new Node(5);
    Node * n6 = new Node(6);
    Node * n7 = new Node(7);
    
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n5->left = n6;
    n5->right = n7;
    
    Node * n = LCA(n1, n4, n2);
    cout << "LCA: " << n->val << endl;
    
    LCA_path(n1, n7, n6);
    
    return 0;
}
