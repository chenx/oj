class Solution2:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        def build(preorder, inorder, pi, li, ri):
            if li > ri:
                return None
            root = TreeNode(preorder[pi])
            mi = valueIndexMap[preorder[pi]]
            root.left = build(preorder, inorder, pi + 1, li, mi - 1)
            root.right = build(preorder, inorder, pi + (mi - li) + 1, mi + 1, ri)
            return root

        valueIndexMap = {}
        for index, val in enumerate(inorder):
            valueIndexMap[val] = index
        return build(preorder, inorder, 0, 0, len(inorder) - 1)


class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        def build(preorder, inorder, pi, li, ri):
            if li > ri:
                return None
            
            root = TreeNode(preorder[pi])
            mi = self.inorderIndexMap[preorder[pi]]
            root.left = build(preorder, inorder, pi + 1, li, mi - 1)
            root.right = build(preorder, inorder, pi + (mi - li) + 1, mi + 1, ri)
            return root

        self.inorderIndexMap = {}
        for i in range(len(inorder)):
            self.inorderIndexMap[inorder[i]] = i

        return build(preorder, inorder, 0, 0, len(preorder) - 1)

/**
105. Construct Binary Tree from Preorder and Inorder Traversal
Solved
Medium
Topics
conpanies iconCompanies

Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree 
and inorder is the inorder traversal of the same tree, construct and return the binary tree.
 */
