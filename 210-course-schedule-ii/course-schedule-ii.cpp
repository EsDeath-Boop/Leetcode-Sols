class Solution {
public:
    vector<int> topoSort(vector<vector<int>>& adj, vector<int>& inDegree, int n){
        queue<int> q;
        vector<int> res;
        int count = 0;

        for(int i = 0; i < n; i++){
            if(inDegree[i] == 0){
                res.push_back(i);
                count++;
                q.push(i);
                
            }
        }

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int &v : adj[u]){
                inDegree[v]--;
                if(inDegree[v] == 0){
                    res.push_back(v);
                    count++;
                    q.push(v);
                }
            }
        }
        if(count == n)
            return res;

        return {};
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        for(auto &vec : prerequisites){
            int a = vec[0];
            int b = vec[1];
            adj[b].push_back(a);
            inDegree[a]++;
        }
        return topoSort(adj, inDegree, numCourses);


    }
};