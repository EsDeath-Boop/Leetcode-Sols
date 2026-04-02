class Solution {
public:
    using p = pair<int, int>;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<p>> adj(n+1);

        for(auto &e : times){
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            adj[u].push_back({v, wt});
        }

        priority_queue<p, vector<p>, greater<p>> minH;
        vector<int> res(n+1, INT_MAX);

        res[k] = 0;
        minH.push({0, k});

        while(!minH.empty()){
            int d = minH.top().first;
            int node = minH.top().second;
            minH.pop();

            for(auto &temp : adj[node]){
                int adjNode = temp.first;
                int wt = temp.second;

                if(d + wt < res[adjNode]){
                    res[adjNode] = d + wt;
                    minH.push({d + wt, adjNode});
                }
            }
        }
        int maxE = 0;

        for(int i = 1; i <= n; i++){
            if(res[i] == INT_MAX) return -1;
            maxE = max(maxE, res[i]);
        }
        return maxE;
    }
};