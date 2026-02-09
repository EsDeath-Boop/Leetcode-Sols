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

    void inorder(TreeNode* root, vector<int>& arr){
        if(root == nullptr) {
            return;
        }
        inorder(root -> left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }

    TreeNode* build(vector<int>& arr, int l, int r){
        if (l > r)
            return nullptr;
        int mid = (l + r) /2;
        return new TreeNode(arr[mid], build(arr, l, mid - 1), build(arr, mid + 1, r));
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        inorder(root, arr);
        return build(arr, 0, arr.size() -1);
    }
};