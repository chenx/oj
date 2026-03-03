# Alternative method: DSW (Day-Stout-Warren) Algorithm / In-Place Balancing
# Also use O(n) time and O(n) space.

# Time: O(n), n = number of nodes, for inorder traversal, and toBalancedTree
# Space: O(n + logn) = O(n)
class Solution:
    def balanceBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def inorder(orderedList, node):
            if not node:
                return
            inorder(orderedList, node.left)
            orderedList.append(node.val)
            inorder(orderedList, node.right)
        
        def toBalancedTree(orderedList, left, right):
            if left > right:
                return None
            mid = left + (right - left) // 2
            root = TreeNode(orderedList[mid])
            root.left = toBalancedTree(orderedList, left, mid - 1)
            root.right = toBalancedTree(orderedList, mid + 1, right)
            return root
        
        orderedList = []
        inorder(orderedList, root)
        return toBalancedTree(orderedList, 0, len(orderedList) - 1)

/**
1382. Balance a Binary Search Tree
Medium
Topics
conpanies iconCompanies
Hint

Given the root of a binary search tree, return a balanced binary search tree with the same node values. 
If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.
 */
