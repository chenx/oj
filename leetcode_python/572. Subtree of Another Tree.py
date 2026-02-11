# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        def isSameTree(root, subRoot):
            if not root and not subRoot:
                return True
            if not root or not subRoot:
                return False
            return root.val == subRoot.val and isSameTree(root.left, subRoot.left) and isSameTree(root.right, subRoot.right)

        if not root:
            return subRoot is None
        if not subRoot:
            return False

        if root.val == subRoot.val and isSameTree(root, subRoot):
            return True
        return self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot)



/**
572. Subtree of Another Tree
Solved
Easy
Topics
conpanies iconCompanies
Hint

Given the roots of two binary trees root and subRoot, return true if there is a subtree of root 
with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's 
descendants. The tree tree could also be considered as a subtree of itself.
 */
