class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        // int i = 0;

        vector<int> leftClosestR(n);
        vector<int> rightClosestL(n);
        string result(n, ' ');

        for(int i =0; i < n; i++){
            if(dominoes[i] == 'R'){
                leftClosestR[i] = i;
            } else if(dominoes[i] == '.'){
                leftClosestR[i] = i > 0 ? leftClosestR[i-1] : -1;
            } else{
                leftClosestR[i] = -1;
            }
        }

        for(int i = n-1; i >=0; i--){
            if(dominoes[i] == 'L'){
                rightClosestL[i] = i;
            } else if(dominoes[i] == '.'){
                rightClosestL[i] = i < (n-1) ? rightClosestL[i+1] : -1;
            } else{
                rightClosestL[i] = -1;
            }
        }

        for(int i =0; i < n; i++){
            int distleftR = abs(i - leftClosestR[i]);
            int distrightL = abs(i- rightClosestL[i]);
            if(rightClosestL[i] == leftClosestR[i]){
                result[i] = '.';
            }else if(rightClosestL[i] == -1){
                result[i] = 'R';
            } else if(leftClosestR[i] == -1){
                result[i] = 'L';
            } else if(distleftR == distrightL){
                result[i] = '.';
            } else{
                result[i] = distleftR < distrightL ? 'R' : 'L';
            }
        }
        return result;
    }
};