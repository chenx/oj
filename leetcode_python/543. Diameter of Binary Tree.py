# Time: O(n)
# Space: O(n), n is call stack depth, which is n when the tree is a linked list.
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        def getDiameter(root):
            nonlocal diameter
            if not root:
                return 0
            
            L = getDiameter(root.left)
            R = getDiameter(root.right)
            diameter = max(diameter, L + R)

            return 1 + max(L, R)
        
        diameter = 0
        getDiameter(root)
        return diameter


/**
543. Diameter of Binary Tree
Solved
Easy
Topics
conpanies iconCompanies

Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 
This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.
 */
