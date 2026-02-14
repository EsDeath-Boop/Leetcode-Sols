class Solution {
public:

    // topological sort using bfs

    // vector<int> topoSort(vector<vector<int>>& adj, vector<int>& inDegree, int n){
    //     queue<int> q;
    //     vector<int> res;
    //     int count = 0;

    //     for(int i = 0; i < n; i++){
    //         if(inDegree[i] == 0){
    //             res.push_back(i);
    //             count++;
    //             q.push(i);
                
    //         }
    //     }

    //     while(!q.empty()){
    //         int u = q.front();
    //         q.pop();

    //         for(int &v : adj[u]){
    //             inDegree[v]--;
    //             if(inDegree[v] == 0){
    //                 res.push_back(v);
    //                 count++;
    //                 q.push(v);
    //             }
    //         }
    //     }
    //     if(count == n)
    //         return res;

    //     return {};
    // }
    // vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    //     vector<int> inDegree(numCourses, 0);
    //     vector<vector<int>> adj(numCourses);

    //     for(auto &vec : prerequisites){
    //         int a = vec[0];
    //         int b = vec[1];
    //         adj[b].push_back(a);
    //         inDegree[a]++;
    //     }
    //     return topoSort(adj, inDegree, numCourses);


    // }

    // topological sort using dfs
    bool hasCycle;

    void topoDFS( vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& inRec, int u, stack<int>& st){
        vis[u] = true;
        inRec[u] = true;

        for(int &v : adj[u]){
            if(inRec[v] == true){
                hasCycle = true;
                return;
            }

            if(!vis[v]){
                topoDFS(adj, vis, inRec, v, st);
            }
        }
        st.push(u);
        inRec[u] = false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<bool> inRec(numCourses, false);
        vector<bool> vis(numCourses, false);
        hasCycle = false;
        for(auto &vec : prerequisites){
            int a = vec[0];
            int b = vec[1];
            adj[b].push_back(a);
        }
        stack<int> st;
        for(int i = 0; i < numCourses; i++){
            if(!vis[i]){
                topoDFS(adj, vis, inRec, i, st);
            }
        }
        if(hasCycle == true){
            return {};
        }

        vector<int> result;

        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
};