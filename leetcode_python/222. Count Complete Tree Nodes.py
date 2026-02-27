# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countNodes(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        
        left, right = 0, 0
        node = root
        while node:
            left += 1
            node = node.left

        node = root
        while node:
            right += 1
            node = node.right
        
        if left == right:
            return 2 ** left - 1
        else:
            return 1 + self.countNodes(root.left) + self.countNodes(root.right)


/**
222. Count Complete Tree Nodes
Solved
Easy
Topics
conpanies iconCompanies

Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, 
and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at 
the last level h.

Design an algorithm that runs in less than O(n) time complexity.
 */
