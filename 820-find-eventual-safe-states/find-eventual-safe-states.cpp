class Solution {
public:
    bool isCycle(vector<vector<int>>& adj, int u, vector<bool>& vis, vector<bool>& inRec){
        vis[u] = true;
        inRec[u] = true;

        for(int &v : adj[u]){
            if(!vis[v] && isCycle(adj, v, vis, inRec)){
                return true;
            } else if(inRec[v] == true){
                return true;
            }
        }
        inRec[u] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<bool> vis(V, false);
        vector<bool> inRec(V, false);

        for(int i = 0; i < V; i++){
            if(!vis[i]){
                isCycle(graph, i, vis, inRec);
            }
        }
        vector<int> safe;
        for(int i = 0; i < V; i++){
            if(inRec[i] == false){
                safe.push_back(i);
            }
        }
        return safe;
    }
};