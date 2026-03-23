# Time: O(n)
# Space: O(1)
class Solution:
    def longestConsecutive(self, root: Optional[TreeNode]) -> int:
        def dfs(node, parent):
            nonlocal maxLen, curLen
            if not node:
                return
            
            if parent is None or parent.val + 1 != node.val:
                curLen = 1
            else:
                curLen += 1
            maxLen = max(maxLen, curLen)
            
            dfs(node.left, node)
            dfs(node.right, node)


        maxLen = 0
        curLen = 0
        dfs(root, None)
        return maxLen
      

/**
298. Binary Tree Longest Consecutive Sequence
Solved
Medium
Topics
conpanies iconCompanies

Given the root of a binary tree, return the length of the longest consecutive sequence path.

A consecutive sequence path is a path where the values increase by one along the path.

Note that the path can start at any node in the tree, and you cannot go from a node to its parent in the path.
 */
