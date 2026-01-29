class Solution2:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        # total is a list, so it's passed by reference of object
        def dfs(node, sum, total):
            if node is None:
                return
            
            sum = sum * 10 + node.val
            if node.left is None and node.right is None:
                total[0] += sum

            if node.left is not None: dfs(node.left, sum, total)
            if node.right is not None: dfs(node.right, sum, total)

        total = [0]
        dfs(root, 0, total)
        return total[0]


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.total = 0

    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        def dfs(node, sum):
            if node is None:
                return
            
            sum = sum * 10 + node.val
            if node.left is None and node.right is None:
                self.total += sum

            if node.left is not None: dfs(node.left, sum)
            if node.right is not None: dfs(node.right, sum)

        self.total = 0
        dfs(root, 0)
        return self.total


/**
129. Sum Root to Leaf Numbers
Solved
Medium
Topics
conpanies iconCompanies

You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

    For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.

Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

A leaf node is a node with no children. 
*/
