class Solution {
public:
    // void build(int i, int l, int r, vector<int>& heights, vector<int>& segT){
    //     if(l == r){
    //         segT[i] = l;
    //         return;
    //     }

    //     int mid = (l + r) / 2;

    //     build(2*i+1, l, mid, heights, segT);
    //     build(2*i+2, mid+1, r, heights, segT);

    //     int leftMaxIdx = segT[2*i+1];
    //     int rightMaxIdx = segT[2*i+2];

    //     if(heights[leftMaxIdx] >= heights[rightMaxIdx])
    //         segT[i] = leftMaxIdx;
    //     else
    //         segT[i] = rightMaxIdx;
        
    // }

    // int query(int st, int end, int i, int l, int r, vector<int>& segT, vector<int>& heights){
    //     if(l > end || r < st)
    //         return -1;

    //     if(l >= st && r <= end){
    //         return segT[i];
    //     }
    //     int mid = l + (r - l) / 2;
    //     int leftMaxIdx = query(st, end, 2*i + 1, l, mid, segT, heights);
    //     int rightMaxIdx = query(st, end, 2*i+2, mid+1, r, segT, heights);

    //     if(heights[leftMaxIdx] >= heights[rightMaxIdx])
    //         segT[i] = leftMaxIdx;
    //     else
    //         segT[i] = rightMaxIdx;

    //     return segT[i];
    // }

    // vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
    //     int n = heights.size();
    //     int q = queries.size();
    //     vector<int> ans;
    //     vector<int> segT(4*n);
    //     build(0, 0, n -1, heights, segT);

    //     for(int i = 0; i < 2*q; i+=2){
    //         int st = queries[i] - 1;
    //         int end = queries[i] + 1;

    //         ans.push_back(query(st, end, 0, 0, n - 1, segT, heights));
    //     }
    //     return ans;
    // }
    void build(int i, int l, int r, vector<int>& heights, vector<int>& segT){
        if( l == r){
            segT[i] = l;
            return;
        }

        int mid = l + (r - l) / 2;

        build(2*i + 1, l, mid, heights, segT);
        build(2*i+2, mid+1, r, heights, segT);

        int leftIdx = segT[2*i + 1];
        int rightIdx = segT[2*i+2];

        if(heights[leftIdx] >= heights[rightIdx]){
            segT[i] = leftIdx;
        }
        else{
            segT[i] = rightIdx;
        }
    }
    int query(int st, int end, int i, int l, int r, vector<int>& segT, vector<int>& heights){
        if(l > end || r < st){
            return -1;
        }

        if(l >= st && r <= end){
            return segT[i];
        }

        int mid = l + (r - l) / 2;

        int leftIdx = query(st, end, 2*i + 1, l, mid, segT, heights);
        int rightIdx = query(st, end, 2*i +2, mid+1, r, segT, heights);
        if(leftIdx == -1) return rightIdx;
        if(rightIdx == -1) return leftIdx;

        if(heights[leftIdx] >= heights[rightIdx]){
            return leftIdx;
        }else{
            return rightIdx;
        }
    }
    int RMIQ(vector<int>& segT, vector<int>& heights, int n, int a, int b){
        return query(a, b, 0, 0, n -1, segT, heights);
    }
    vector<int> constructST(vector<int>& heights, int n){
        vector<int> segT(4*n);
        build(0, 0, n - 1, heights, segT);  
        return segT;
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries){
        int n = heights.size();
        vector<int> segT = constructST(heights, n);

        vector<int> result;

        for(auto query : queries){
            int min_idx = min(query[0], query[1]);
            int max_idx = max(query[0], query[1]);

            if(min_idx == max_idx){
                result.push_back(min_idx);
                continue;
            }
            else if(heights[max_idx] > heights[min_idx]){
                result.push_back(max_idx);
                continue;
            }
            int l = max_idx +1;
            int r = n -1; 
            int result_idx = INT_MAX;
            while(l <= r){
                int mid = l + ( r - l)  / 2;
                int idx = RMIQ(segT, heights, n, l, mid);

                if(idx != -1 && heights[idx] > max(heights[max_idx], heights[min_idx])){
                    result_idx = min(result_idx, idx);
                    r = mid - 1;

                } else{
                    l = mid + 1;
        
                }
                
            }

            if(result_idx == INT_MAX)
                result.push_back(-1);
            else{
                result.push_back(result_idx);
            }
        }
        return result;
    }

};