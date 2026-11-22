# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        
        def dfs(p: TreeNode):
            if not p:
                return 0, 0
                #longest together, longest individual
            a = dfs(p.left)
            b = dfs(p.right)
            return [max(a[1] + b[1], a[0], b[0]), max(a[1], b[1])+1]

        return dfs(root)[0]