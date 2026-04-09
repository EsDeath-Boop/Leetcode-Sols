class Solution {
public:
    typedef pair<int, pair<int, int>> P; 
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> res(m, vector<int>(n, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> minH;

        auto isSafe = [&](int x, int y){
            return x >= 0 && y >= 0 && x < m && y < n;
        };
        res[0][0] = 0;
        minH.push({0, {0, 0}});

        while(!minH.empty()){
            int diff = minH.top().first;
            auto cord = minH.top().second;
            minH.pop();
            int x = cord.first;
            int y = cord.second;

            for(auto &dir : dirs){
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if(isSafe(x_, y_)){
                    int absDiff = abs(heights[x][y] - heights[x_][y_]);
                    int maxDiff = max(diff, absDiff);

                    if(res[x_][y_] > maxDiff){
                        res[x_][y_] = maxDiff;
                        minH.push({maxDiff, {x_, y_}});
                    }
                }
            }
        }
        return res[m-1][n-1];
    }
};