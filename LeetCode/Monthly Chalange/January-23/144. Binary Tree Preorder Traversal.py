# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.traversal_order = []
    def traverse(self, root):
        if root is None:
            return
        self.traversal_order.append(root.val)
        self.traverse(root.left)
        self.traverse(root.right)
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        self.traverse(root)
        return self.traversal_order