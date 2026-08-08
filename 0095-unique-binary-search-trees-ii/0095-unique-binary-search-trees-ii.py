# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        
        def build(start, end):
            if start > end:
                return [None]

            result = []

            # Try every value as root
            for root in range(start, end + 1):

                left_trees = build(start, root - 1)
                right_trees = build(root + 1, end)

                # Combine every left tree with every right tree
                for left in left_trees:
                    for right in right_trees:
                        root_node = TreeNode(root)
                        root_node.left = left
                        root_node.right = right
                        result.append(root_node)

            return result

        return build(1, n)