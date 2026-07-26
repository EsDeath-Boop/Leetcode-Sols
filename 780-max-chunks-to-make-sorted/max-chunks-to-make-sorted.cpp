class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();

        vector<int> prefix(begin(arr), end(arr));
        vector<int> suffix(begin(arr), end(arr));

        for(int i = 1; i < n; i++){
            prefix[i] = max(arr[i], prefix[i-1]);
        }

        for(int i = n-2; i >= 0; i--){
            suffix[i] = min(arr[i], suffix[i+1]);
        }

        int count = 0;

        for(int i = 0; i < n; i++){
            int pehlekaMax = i > 0 ? prefix[i-1] : -1;
            int baadkaMin = suffix[i];

            if(pehlekaMax < baadkaMin)
                count++;
        }

        return count;
    }
};