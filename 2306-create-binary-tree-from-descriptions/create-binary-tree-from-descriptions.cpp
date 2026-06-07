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
    TreeNode* createBinaryTree(vector<vector<int>>& a) {
        int root = 0;

        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> children;

        for(auto &d : a){
            int par = d[0];
            int child = d[1];
            int isLeft = d[2];

            if(!nodes.count(par)){
                nodes[par] = new TreeNode(par);
            }

            if(!nodes.count(child)){
                nodes[child] = new TreeNode(child);
            }

            if(isLeft){
                nodes[par] -> left = nodes[child];
            }else{
                nodes[par] -> right = nodes[child];
            }

            children.insert(child);
        }

        for(auto &[val, node] : nodes){
            if(!children.count(val)){
                return node;
            }
        }

        return nullptr;
    }
};