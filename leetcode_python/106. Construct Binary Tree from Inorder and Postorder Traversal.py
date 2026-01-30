# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        def build(postorder, inorder, pi, li, ri):
            if li > ri:
                return None
            
            root = TreeNode(postorder[pi])
            mi = self.inorderIndexMap[postorder[pi]]
            root.left = build(postorder, inorder, pi - (ri - mi) - 1, li, mi - 1)
            root.right = build(postorder, inorder, pi - 1, mi + 1, ri)
            return root

        n = len(inorder)
        self.inorderIndexMap = {}
        for i in range(n):
            self.inorderIndexMap[inorder[i]] = i

        return build(postorder, inorder, n-1, 0, n - 1)

/**
106. Construct Binary Tree from Inorder and Postorder Traversal
Solved
Medium
Topics
conpanies iconCompanies

Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree 
and postorder is the postorder traversal of the same tree, construct and return the binary tree.
 */
