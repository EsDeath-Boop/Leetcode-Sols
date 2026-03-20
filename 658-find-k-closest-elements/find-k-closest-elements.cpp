class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> maxH;
        int n = arr.size();
        vector<int> res;

        for(int i = 0; i < n; i++){
            maxH.push({abs(x - arr[i]), arr[i]});

            if(maxH.size() > k)
                maxH.pop();
        }

        while(maxH.size()){
            res.push_back(maxH.top().second);
            maxH.pop();
        }
        sort(res.begin(), res.end());
        return res;
    }
};