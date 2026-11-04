/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void dfs(TreeNode* root, vector<string>& path,
             vector<string>& paths) {
        if (root == nullptr) return;

        if (root->left == nullptr && root->right == nullptr) {
            string current;
            for (const string& part : path) current += part;
            paths.push_back(current + to_string(root->val));
            return;
        }

        path.push_back(to_string(root->val) + "->");
        dfs(root->left, path, paths);
        dfs(root->right, path, paths);
        path.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        vector<string> path;
        dfs(root, path, paths);
        return paths;
    }
};