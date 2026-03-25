class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        stack = []
        node = root

        while True:
            while node:
                stack.append(node)
                node = node.left
            
            if not stack:
                break
            
            node = stack.pop()
            result.append(node.val)
            node = node.right
        
        return result


/**
94. Binary Tree Inorder Traversal
Solved
Easy
Topics
conpanies iconCompanies

Given the root of a binary tree, return the inorder traversal of its nodes' values.

 

Example 1:

Input: root = [1,null,2,3]

Output: [1,3,2]
 */
