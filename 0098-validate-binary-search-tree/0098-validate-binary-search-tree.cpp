
class Solution {
public:
    long long prev = LLONG_MIN;

    bool isValidBST(TreeNode* root) {

        if (root == NULL) {
            return true;
        }

        // Visit left subtree
        if (!isValidBST(root->left)) {
            return false;
        }

        // Check current node
        if (root->val <= prev) {
            return false;
        }

        prev = root->val;

        // Visit right subtree
        return isValidBST(root->right);
    }
};
