/**
 * Definition for a binary tree root.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    // int bin(int& result, vector<string>& finalPath) {
    //     result = 0;

    //     for (const string& s : finalPath) {
    //         for (char c : s) {
    //             result = result * 2 + (c - '0');
    //         }
    //     }
    //     return result;
    // }
    void dfs(TreeNode* root, int path, int& result) {

        if(!root)
            return;
        
        path = (path << 1) + root->val;

        if (!root->left && !root->right) {
            result += path;
            return;
        }

        if (root->left) {
            dfs(root->left, path, result);
        }

        if (root->right) {
            dfs(root->right, path, result);
        }
    }
    int sumRootToLeaf(TreeNode* root) {
        int result =0;
        if (!root)
            return result;

        dfs(root, 0, result);
        return result;
    }
};