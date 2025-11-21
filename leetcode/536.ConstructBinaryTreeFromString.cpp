// Recursive.
// From: https://leetcode.com/problems/construct-binary-tree-from-string/editorial/
// Time Complexity: O(N) where N represents the number of characters in the string representation.
// Space Complexity: O(H) where H represents the height of the tree. H <= N.
class Solution {
public:
    TreeNode* str2tree(string s) {
        return str2treeInternal(s, 0).first;
    }
    
    pair<int, int> getNumber(string& s, int index) {
        bool isNegative = false;
        
        // A negative number
        if (s[index] == '-') {
            isNegative = true;
            index++;
        }
            
        int number = 0;
        while (index < s.length() && isdigit(s[index])) {
            number = number * 10 + (s[index] - '0');
            index++;
        }
        
        return {isNegative ? -number : number, index};
    } 
    
    pair<TreeNode*, int> str2treeInternal(string& s, int index) {
        if (index == s.length()) {
            return {NULL, index};
        }
        
        // Start of the tree will always contain a number representing
        // the root of the tree. So we calculate that first.
        pair<int, int> numberData = getNumber(s, index);
        int value = numberData.first;
        index = numberData.second;
        
        TreeNode* node = new TreeNode(value);
        pair<TreeNode*, int> data;
        
        // Next, if there is any data left, we check for the first subtree
        // which according to the problem statement will always be the left child.
        if (index < s.length() && s[index] == '(') {
            data = str2treeInternal(s, index + 1);
            node->left = data.first;
            index = data.second;
        }
            
        // Indicates a right child
        if (node->left != NULL && index < s.length() && s[index] == '(') {
            data = str2treeInternal(s, index + 1);
            node->right = data.first;
            index = data.second;
        }
        
        return {node, (index < s.length() && s[index] == ')') ? index + 1 : index};
    }
};

/**
536. Construct Binary Tree from String
Medium

You need to construct a binary tree from a string consisting of parenthesis and integers.

The whole input represents a binary tree. It contains an integer followed by zero, one or 
two pairs of parenthesis. The integer represents the root's value and a pair of parenthesis 
contains a child binary tree with the same structure.

You always start to construct the left child node of the parent first if it exists.
 */
