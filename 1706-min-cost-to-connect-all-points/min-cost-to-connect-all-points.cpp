class Solution {
public:
    using p = pair<int, int>;

    int primAlgo(vector<vector<pair<int, int>>>& adj, int V){
        priority_queue<p, vector<p>, greater<p>> minH;
        vector<bool> inMST(V, false);

        minH.push({0, 0}); 
        int sum = 0;

        while(!minH.empty()){
            auto it = minH.top();
            minH.pop();

            int wt = it.first;
            int node = it.second;

            if(inMST[node]) continue;

            inMST[node] = true;
            sum += wt;

            for(auto &temp : adj[node]){
                int neigh = temp.first;
                int dist = temp.second;

                if(!inMST[neigh]){
                    minH.push({dist, neigh}); 
                }
            }
        }
        return sum;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        vector<vector<pair<int, int>>> adj(V);

        for(int i = 0; i < V; i++){
            for(int j = i + 1; j < V; j++){
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];

                int diff = abs(x1 - x2) + abs(y1 - y2);

                adj[i].push_back({j, diff});
                adj[j].push_back({i, diff});
            }
        }

        return primAlgo(adj, V);
    }
};