class Solution {
public:
    void dfs(int u, vector<vector<int>>& adj, vector<int>& comp, int compId){
        comp[u] = compId;

        for(auto &child : adj[u]){
            if(comp[child] == -1){
                dfs(child, adj, comp, compId);
            }
        } 
    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);

        for(int i = 0; i < n-1; i++){
            if(nums[i+1] - nums[i] <= maxDiff){
                adj[i].push_back(i+1);
                adj[i+1].push_back(i);
            }
        }

        vector<int> comp(n, -1);
        int compId = 0;

        for(int i = 0; i < n; i++){
            if(comp[i] == -1){
                dfs(i, adj, comp, compId);
                compId++;
            }
        }
        vector<bool> res;

        for(auto &q : queries){
            if(comp[q[0]] == comp[q[1]]){
                res.push_back(1);
            }else
                res.push_back(0);
        }
        return res;
    }
};  