class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        def getPath(node, path, sum):  # path must be passed by value.
            if not node:
                return
            
            sum -= node.val
            path.append(node.val)
            if node.left is None and node.right is None:
                if sum == 0:
                    result.append(path)
                return
            
            getPath(node.left, path[:], sum)
            getPath(node.right, path[:], sum)
        
        result = []
        path = []
        getPath(root, path, targetSum)
        return result

/**
113. Path Sum II
Solved
Medium
Topics
conpanies iconCompanies

Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths 
where the sum of the node values in the path equals targetSum. Each path should be returned 
as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. 
A leaf is a node with no children.
 */
