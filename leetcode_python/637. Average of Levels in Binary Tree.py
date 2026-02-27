# Time: O(n), n = number of nodes. Each node is visited once.
# Space: O(n), is max number of nodes in any level, which max to n/2. result can be O(n) when tree is a chain.
from collections import deque

class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        if not root:
            return []
        
        result = []
        q = deque([root])
        while q:
            count = len(q)
            sum = 0
            for i in range(count):
                node = q.popleft()
                sum += node.val
                if node.left: q.append(node.left)
                if node.right: q.append(node.right)
            result.append(sum / count)
        return result


/**
637. Average of Levels in Binary Tree
Solved
Easy
Topics
conpanies iconCompanies
Given the root of a binary tree, return the average value of the nodes on each level in the form of an array. 
Answers within 10-5 of the actual answer will be accepted.
 */
