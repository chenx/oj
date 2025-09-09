// Recursive
void inorder(TreeNode* root, vector<int>& ans) {
  if (!root) return;

  preorder(root->left);
  preorder(root->right);
  ans.push_back(root->val);
}

// Iterative
class Solution {
public:
   vector<int> postorderTraversal(TreeNode* root) {
       vector<int> result;
       if (!root) return result;

       stack<TreeNode *> s;
       s.push(root);
       while(!s.empty()) {
           TreeNode* n = s.top();
           s.pop();
           result.push_back(n->val);

           if (n->left) s.push(n->left);
           if (n->right) s.push(n->right);
       }
       reverse(result.begin(), result.end());

       return result;
   }
};

