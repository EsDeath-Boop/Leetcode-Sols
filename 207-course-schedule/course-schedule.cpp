class Solution {
public:

    // dfs

    // bool isCycleDFS(vector<vector<int>>& adj, int u, vector<bool>& vis, vector<bool>& inRec){
    //     vis[u] = true;
    //     inRec[u] = true;

    //     for(int &v :adj[u]){
    //         if(!vis[v] && isCycleDFS(adj, v, vis, inRec))
    //             return true;
    //         else if(inRec[v] == true)
    //             return true;
    //     }
    //     inRec[u] = false;
    //     return false;
    // }
    // bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    //     vector<bool> inRec(numCourses, false);
    //     vector<bool> vis(numCourses, false);
    //     vector<vector<int>> adj(numCourses);

    //     for(auto &vec : prerequisites){
    //         int a = vec[0];
    //         int b = vec[1];
    //         adj[b].push_back(a);

    //     }
    //     for(int i =0; i < numCourses; i++){
    //         if(vis[i] == false && isCycleDFS(adj, i, vis, inRec))
    //             return false;
    //     }
    //     return true;
    // }

    // bfs
    bool topoSort(vector<vector<int>>& adj, vector<int>& inDegree, int n){
        queue<int> q;
        int count = 0;

        for(int i  =0; i < n; i++){
            if(inDegree[i] == 0){
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
                    count++;
                    q.push(v);
                }
            }
        }
        if(count == n){
            return true;
        }
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);

        for(auto &vec : prerequisites){
            int a = vec[0];
            int b = vec[1];
            adj[b].push_back(a);

            inDegree[a]++;
        }

        return topoSort(adj, inDegree, numCourses);
    }
};

