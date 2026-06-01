class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();

        sort(cost.begin(), cost.end(), greater<int>());
        int ans = 0;

        // int sum = cost[n-1] + cost[n-2] + cost[n-3];

        for(int i = 0; i < n; i++){
            if(i % 3 != 2)
                ans += cost[i];
        }

        return ans;
    }
};