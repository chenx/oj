//
// See below for problem description.
// 11/21/2013
//

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int v) : val(v), left(NULL), right(NULL) {}
};

void dump(TreeNode * n, int h) {
    if (! n) return;
    dump(n->right, h+1);
    for (int i = 0; i < h; ++ i) cout << "  ";
    cout << n->val << endl;
    dump(n->left, h+1);
}

void drawTree(TreeNode * n) {
    dump(n, 0);
    cout << endl << endl;
}

// solution to first problem. Works.
TreeNode * cousin(TreeNode * n) {
    if (! n) return NULL;
    TreeNode *h = n, *R = n->right; 
    
    n = n->left; 
    h->left = NULL;
    h->right = NULL;
    
    while(n) {
        TreeNode * tmp = n, *tmp_r = n->right;
        
        n = n->left;
        tmp->right = h;
        tmp->left = R;
        R = tmp_r;
        h = tmp;
    }
    
    return h;
}

// solution to second problem. Works.
TreeNode * cousin2(TreeNode * n) {
    if (! n) return NULL;
    TreeNode * R = n->right, * root = n;
    n->right = NULL;
    
    while (n && n->left) {
        TreeNode * tmp_r = n->left->right;
        n->left->right = R;
        R = tmp_r;
        n = n->left;
    }
    
    return root;
}

// Another solution to first problem. Works.
// by: akzhd
TreeNode* ConvertTree(TreeNode *root)
{
    if(!root) return NULL;
    if(!root->left && !root->right) return root;
    TreeNode* res=ConvertTree(root->left);
    root->left->left=root->right;
    root->left->right=root;
    root->left=root->right=NULL;
    return res;
}

// Another solution to first problem. Works.
// by: lcheng16 
TreeNode* upDown(TreeNode* root)
{
    if(!root)
        return root;
    TreeNode* rightCousin = NULL;
    TreeNode* parent = NULL;
    TreeNode* temp;
    while(root)
    {
        temp = root -> left;
        root -> left = rightCousin;
        rightCousin = root -> right;
        root -> right = parent;
        parent = root;
        root = temp;
    }
    if(rightCousin)
    {
        rightCousin->left = parent;
        return rightCousin;
    }
    return parent;
}

void test1() {
    TreeNode * r = new TreeNode(1);
    r->left = new TreeNode(2);
    r->right = new TreeNode(3);
    r->left->left = new TreeNode(4);
    r->left->left->left = new TreeNode(5);
    r->left->left->right = new TreeNode(6);
    drawTree(r);
        
//    TreeNode * c = cousin(r);
//    TreeNode * c = ConvertTree(r);
    TreeNode * c = upDown(r);
    drawTree(c);
}

void test2() {
    TreeNode * r = new TreeNode(1);
    r->left = new TreeNode(2);
    r->right = new TreeNode(3);
    r->left->left = new TreeNode(4);
    r->left->left->left = new TreeNode(5);
    r->left->left->right = new TreeNode(6);
    drawTree(r);
        
    TreeNode * c = cousin2(r);
    drawTree(c);
}


int main() {
    test1();
    test2();
    return 0;
}


/*
http://www.mitbbs.com/article_t/JobHunting/32582231.html

???: DK100 (dark knight), ??: JobHunting
???: BBS ????? (Wed Nov 20 20:33:09 2013, ??)

Given a binary tree where all the right nodes are either empty or leaf nodes
, flip it upside down and turn it into a tree with left leaf nodes.
In the original tree, if a node has right child, it must has left child.

for example, turn these:

         1                1
        /               /
       2   3           2   3
      /
     4
    /
   5   6

  into these:

         1               1
        /               /
       2---3           2---3   
      /
     4
    /
   5---6

  where 5 is the new root node for the left tree, and 2 for the right tree.
  oriented correctly:

      5                  2
     / \               /
    6   4             3   1
         \
          2
         / \
        3   1



Another alternative problem: same condition, convert tree to this:
        1              1
       /              /
      2              2 
     / \              \
    4   3              3
   /     
  5     
   \
    6

 */
