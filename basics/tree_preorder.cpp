// Recursive
void preorder(TreeNode* root, vector<int>& ans) {
  if (!root) return;

  ans.push_back(root->val);
  preorder(root->left);
  preorder(root->right);
}

// Iterative
void preorder(TreeNode* root, vector<int>& ans) {
  if (!root) return;

  stack<TreeNode *> s;  // use stack not queue!
  s.push(root);
  while(!s.empty()) {
    TreeNode* n = s.top();
    s.pop();
    result.push_back(n->val);

    if (n->right) s.push(n->right);
    if (n->left) s.push(n->left);
  }
}
