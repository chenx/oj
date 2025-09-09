void lever_order(TreeNode* root, vector<int>& ans) {
  if (!root) return;

  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    for (int i = 0, len = q.size(); i < len; ++ i) {
      TreeNode* n = q.front();
      q.pop();
      
      ans.push_back(n->val);

      if (n->left) q.push(n->left);
      if (n->right) q.push(n->right);
    }
  }
}
