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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr)
            return {};

        queue<pair<TreeNode*, int>> q;
        map<int, int> mp;
        q.push({root, 0});

        while(!q.empty()){
            TreeNode* curr = q.front().first;
            int currD = q.front().second;
            q.pop();

            mp[currD] = curr -> val;

            if(curr -> left != NULL)
                q.push({curr -> left, currD + 1});

            if(curr -> right != nullptr)
                q.push({curr -> right, currD + 1});
        }

        vector<int> ans;

        for(auto &p : mp){
            int u = p.second;
            ans.push_back(u);
        }

        return ans;
    }
};