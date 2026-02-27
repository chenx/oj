# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []

        result = []
        q = deque([root])
        while q:
            count = len(q)
            for i in range(count):
                node = q.popleft()
                if node.left: q.append(node.left)
                if node.right: q.append(node.right)

                if i == count - 1:
                    result.append(node.val)
        return result


/**
199. Binary Tree Right Side View
Solved
Medium
Topics
conpanies iconCompanies

Given the root of a binary tree, imagine yourself standing on the right side of it, 
return the values of the nodes you can see ordered from top to bottom.

 

Example 1:

Input: root = [1,2,3,null,5,null,4]

Output: [1,3,4]
 */
