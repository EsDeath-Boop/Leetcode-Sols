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
    // int maxDepth = 0;
    // unordered_map<int, int> mp;

    // void depth(TreeNode* root, int d){
    //     if(!root)
    //         return;

    //     maxDepth = max(maxDepth, d);
    //     mp[root->val] = d;
    //     depth(root->left, d+1);
    //     depth(root->right, d+1);
    // }

    // TreeNode* LCA(TreeNode* root){
    //     if(!root || mp[root->val] == maxDepth)
    //         return root;

    //     TreeNode* p = LCA(root->left);
    //     TreeNode* q = LCA(root->right);

    //     if(p && q)
    //         return root;

    //     return p != nullptr ? p : q;
    // }

    // TreeNode* lcaDeepestLeaves(TreeNode* root) {
    //     depth(root, 0);
    //     return LCA(root);
    // }

    pair<int, TreeNode*> solve(TreeNode* root){
        if(!root)
            return {0, NULL};

        auto left = solve(root->left);
        auto right = solve(root->right);

        if(left.first == right.first){
            return {left.first + 1, root};
        } else if(left.first > right.first){
            return {left.first+1, left.second};
        } else{
            return {right.first+1, right.second};
        }
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root){
        return solve(root).second;
    }
};