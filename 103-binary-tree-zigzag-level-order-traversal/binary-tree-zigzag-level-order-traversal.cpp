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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;

        queue<TreeNode*> q;
        q.push(root);

        bool leftRight = true;

        while(!q.empty()){
            int size = q.size();
            vector<int> lev(size);

            for(int i = 0; i < size; i++){
                TreeNode* curr = q.front();
                q.pop();
                int idx;
                if(leftRight)
                    idx = i;
                else
                    idx = size - i - 1;

                lev[idx] = curr -> val;

                if(curr -> left)
                    q.push(curr -> left);
                if(curr -> right)
                    q.push(curr -> right);
            }
            leftRight = !leftRight;
            result.push_back(lev);
        }
        return result;
    }
};