# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        if root is None:
            return True
        
        return self.isSymmetricTree(root.left, root.right)
    
    def isSymmetricTree(self, left, right):
        if left is None and right is None:
            return True
        if left is None or right is None:
            return False
        
        return left.val == right.val and \
            self.isSymmetricTree(left.left, right.right) and \
            self.isSymmetricTree(left.right, right.left)

/**
101. Symmetric Tree
Solved
Easy
Topics
conpanies iconCompanies

Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
 */
