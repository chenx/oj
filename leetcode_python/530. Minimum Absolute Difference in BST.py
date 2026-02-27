# Time: O(n)
# Space: O(n) for recursion call stack.
class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        def dfs(node):
            nonlocal prev, minDiff
            if not node:
                return
            
            dfs(node.left)
            if prev:
                diff = node.val - prev.val
                if minDiff == -1 or minDiff > diff:
                    minDiff = diff
            prev = node
            dfs(node.right)
        
        minDiff = -1
        prev = None
        dfs(root)
        return minDiff

/**
530. Minimum Absolute Difference in BST
Solved
Easy
Topics
conpanies iconCompanies

Given the root of a Binary Search Tree (BST), return the minimum absolute difference between 
the values of any two different nodes in the tree.
 */
