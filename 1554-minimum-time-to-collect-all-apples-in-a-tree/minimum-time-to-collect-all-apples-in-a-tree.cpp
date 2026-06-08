class Solution {
public:
    int dfs(vector<vector<int>>& adj, int curr, int parent, vector<bool>& hasApple){
        int time = 0;

        for(auto child : adj[curr]){
            if(child == parent)
                continue;

            int timeChild = dfs(adj, child, curr, hasApple);

            if(timeChild > 0 || hasApple[child])
                time += 2 + timeChild;   
        }

        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);

        for(auto &e : edges){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return dfs(adj, 0, -1, hasApple);
    }
};