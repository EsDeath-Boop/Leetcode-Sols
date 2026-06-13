class Solution {
public:
    int timeRequiredToBuy(vector<int>& arr, int k) {
        int t = 0;
        int n = arr.size();

        while(true){
            
            for(int i = 0; i < n; i++){
                if(arr[i] > 0){
                    arr[i] = arr[i] - 1;
                    t++;
                }
                if(i == k && arr[i] == 0)
                    return t;
            }
        }
        return 0;
    }
};