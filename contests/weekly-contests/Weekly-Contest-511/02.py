# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def countDominantNodes(self, root: TreeNode | None) -> int:
        dominant_count = 0

        def dfs(node):
            nonlocal dominant_count

            if node is None:
                return float("-inf")

            left_max = dfs(node.left)
            right_max = dfs(node.right)

            if node.val >= left_max and node.val >= right_max:
                dominant_count += 1

            return max(node.val, left_max, right_max)

        dfs(root)
        return dominant_count