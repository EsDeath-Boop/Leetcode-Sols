// class Solution {
// public:
//     void dfs(int u, int parent, int dist, vector<vector<int>>& adj, int &sum) {
//         sum += dist;

//         for (int v : adj[u]) {
//             if (v != parent) {
//                 dfs(v, u, dist + 1, adj, sum);
//             }
//         }
//     }

//     vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
//         vector<vector<int>> adj(n);

//         for (auto &e : edges) {
//             adj[e[0]].push_back(e[1]);
//             adj[e[1]].push_back(e[0]);
//         }

//         vector<int> ans(n);

//         for (int i = 0; i < n; i++) {
//             int sum = 0;
//             dfs(i, -1, 0, adj, sum);
//             ans[i] = sum;
//         }

//         return ans;
//     }
// };

class Solution{
public:
    int dfsRoot(vector<vector<int>> &adj, int curr, int depth, long &rootRes, vector<int> &count, int prev, int n){
        int totalCount = 1;
        rootRes += depth;

        for(auto &child : adj[curr]){
            if(child == prev)
                continue;

            totalCount += dfsRoot(adj, child, depth+1, rootRes, count, curr, n);
        }
        count[curr] = totalCount;

        return totalCount;
    }

    void dfs(vector<vector<int>> &adj, int curr, int prev, vector<int>& res, int n, vector<int>& count){
        for(auto &child : adj[curr]){
            if(child == prev)
                continue;

            res[child] = res[curr] - count[child] + (n - count[child]);

            dfs(adj, child, curr, res, n, count);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges){
        vector<vector<int>> adj(n);
        vector<int> count(n, 0);

        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        long rootRes = 0;
        dfsRoot(adj, 0, 0, rootRes, count, -1, n); 

        vector<int> res(n, 0);
        res[0] = rootRes;
        
        dfs(adj, 0, -1, res, n, count);
        return res;  
    }
};