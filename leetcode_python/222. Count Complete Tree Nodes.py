# Binary search.
# See https://leetcode.com/problems/count-complete-tree-nodes/editorial/
# Time: O(d^2), d = log(n)
# Space: O(1)
class Solution3:
    def compute_depth(self, node: TreeNode) -> int:
        """
        Return tree depth in O(d) time.
        """
        d = 0
        while node.left:
            node = node.left
            d += 1
        return d

    def exists(self, idx: int, d: int, node: TreeNode) -> bool:
        """
        Last level nodes are enumerated from 0 to 2**d - 1 (left -> right).
        Return True if last level node idx exists. 
        Binary search with O(d) complexity.
        """
        left, right = 0, 2**d - 1
        for _ in range(d):
            pivot = left + (right - left) // 2
            if idx <= pivot:
                node = node.left
                right = pivot
            else:
                node = node.right
                left = pivot + 1
        return node is not None
        
    def countNodes(self, root: TreeNode) -> int:
        # if the tree is empty
        if not root:
            return 0
        
        d = self.compute_depth(root)
        # if the tree contains 1 node
        if d == 0:
            return 1
        
        # Last level nodes are enumerated from 0 to 2**d - 1 (left -> right).
        # Perform binary search to check how many nodes exist.
        left, right = 1, 2**d - 1
        while left <= right:
            pivot = left + (right - left) // 2
            if self.exists(pivot, d, root):
                left = pivot + 1
            else:
                right = pivot - 1
        
        # The tree contains 2**d - 1 nodes on the first (d - 1) levels
        # and left nodes on the last level.
        return (2**d - 1) + left


# Time：O(n)
# Space: O(1)
class Solution2:
    def countNodes(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        
        return 1 + self.countNodes(root.left) + self.countNodes(root.right)


# Time: O(n^2)
# Space: O(1)
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
