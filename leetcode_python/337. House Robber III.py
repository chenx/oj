# This works too.
class Solution2:
    def __init__(self):
        self.cache : dict[node, int] = {}

    def rob(self, root: Optional[TreeNode]) -> int:
        def getCachedVal(node):
            if not node:
                return 0
            if not node in self.cache:
                self.cache[node] = self.rob(node)
            return self.cache[node]
            
        def robRoot(root):
            if not root:
                return 0
            return root.val + robNotRoot(root.left) + robNotRoot(root.right)

        def robNotRoot(root):
            if not root:
                return 0
            return getCachedVal(root.left) + getCachedVal(root.right)

        if not root:
            return 0
        return max(robRoot(root), robNotRoot(root))


class Solution:
    def __init__(self):
        self.cache : dict[node, int] = {}

    def rob(self, root: Optional[TreeNode]) -> int:
        def getCachedVal(node):
            if not node:
                return 0
            if not node in self.cache:
                self.cache[node] = self.rob(node)
            return self.cache[node]
            
        if not root:
            return 0

        v1 = getCachedVal(root.left) + getCachedVal(root.right)

        v2 = root.val
        if root.left:
            v2 += getCachedVal(root.left.left) + getCachedVal(root.left.right)
        if root.right:
            v2 += getCachedVal(root.right.left) + getCachedVal(root.right.right)

        return max(v1, v2)
    

/**
337. House Robber III
Solved
Medium
Topics
conpanies iconCompanies

The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses 
in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken 
into on the same night.

Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.
 */
