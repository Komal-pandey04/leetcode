# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def printTree(self, root: Optional[TreeNode]) -> List[List[str]]:

        # Find the height of the tree
        def height(node):
            if not node:
                return -1
            return 1 + max(height(node.left), height(node.right))

        h = height(root)

        rows = h + 1
        cols = (2 ** (h + 1)) - 1

        # Create the result matrix filled with empty strings
        res = [[""] * cols for _ in range(rows)]

        # Fill the matrix using DFS
        def dfs(node, row, left, right):
            if not node:
                return

            mid = (left + right) // 2
            res[row][mid] = str(node.val)

            dfs(node.left, row + 1, left, mid - 1)
            dfs(node.right, row + 1, mid + 1, right)

        dfs(root, 0, 0, cols - 1)

        return res