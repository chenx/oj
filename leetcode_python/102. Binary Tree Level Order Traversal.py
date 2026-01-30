# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []

        result = []
        q = collections.deque([root])

        while len(q) > 0:
            count = len(q)
            row = []
            for i in range(count):
                node = q.popleft()
                row.append(node.val)

                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            result.append(row)
        
        return result


/**
102. Binary Tree Level Order Traversal
Solved
Medium
Topics
conpanies iconCompanies
Hint

Given the root of a binary tree, return the level order traversal of its nodes' values. 
(i.e., from left to right, level by level).
 */
