# Note use of:
#   -float("inf") for INT_MIN
#   nonlocal
class Solution2:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        maxSum = - float("inf")
        def getMaxSum(node : TreeNode) -> int:
            nonlocal maxSum

            if node is None:
                return 0
            
            L = getMaxSum(node.left)
            R = getMaxSum(node.right)
            maxSum = max(maxSum, node.val + L + R)

            return max(0, node.val + max(L, R))

        if root is None: return 0
        getMaxSum(root)
        return maxSum


class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        def getMaxSum(node : TreeNode, maxSum : list[int]) -> int:
            if node is None:
                return 0
            
            L = getMaxSum(node.left, maxSum)
            R = getMaxSum(node.right, maxSum)
            maxSum[0] = max(maxSum[0], node.val + L + R)

            return max(0, node.val + max(L, R))

        if root is None: return 0
        maxSum = [-float("inf")]  # [- sys.maxsize - 1]
        getMaxSum(root, maxSum)
        return maxSum[0]

/**
124. Binary Tree Maximum Path Sum
Solved
Hard
Topics
conpanies iconCompanies

A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence 
has an edge connecting them. A node can only appear in the sequence at most once. Note that the 
path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.
 */
