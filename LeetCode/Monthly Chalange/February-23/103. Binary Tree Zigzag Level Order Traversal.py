# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.zig = []
        
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        self.dfs(root, 1, 0)
        for i in range (1, len(self.zig), 2):
            self.zig[i].reverse()
        return self.zig
    
    def dfs(self, root: Optional[TreeNode],f:bool, lv: int) -> None:
        if not root:
            return
        if lv>=len(self.zig):
            self.zig.append([])
        
        self.zig[lv].append(root.val)
        
        if root.left:
            self.dfs(root.left, not f, lv+1)
        if root.right:
            self.dfs(root.right, not f, lv+1)
        