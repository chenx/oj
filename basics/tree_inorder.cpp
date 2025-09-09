// Recursive
void inorder(TreeNode* root, vector<int>& ans) {
  if (!root) return;

  preorder(root->left);
  ans.push_back(root->val);
  preorder(root->right);
}

// Iterative
void inorder(TreeNode* root, vector<int>& ans) {
  if (!root) return;

  stack<TreeNode*> s;
  TreeNode* n = root;

  while (true) {
    while(n) {
        s.push(n);
        n = n->left;
    }

    if (s.empty()) break;
      
    n = s.top();
    s.pop();
    ans.push_back(n->val);
    n = n->right;
  }
}
