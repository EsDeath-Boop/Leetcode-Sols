/**
 * Definition for a binary tree node.
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
    void dfs(TreeNode* node, int path, int& result) {

        if(!node)
            return;
        
        path = (path << 1) + node->val;

        if (!node->left && !node->right) {
            result += path;
            return;
        }

        if (node->left) {
            dfs(node->left, path, result);
        }

        if (node->right) {
            dfs(node->right, path, result);
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