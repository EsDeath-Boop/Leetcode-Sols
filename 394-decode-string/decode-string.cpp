class Solution {
public:
    string decodeString(string s) {
        stack<int>inst;
        stack<string>ststring;
        int currno=0;
        string currstr="";
        for(auto it:s){
            if(isdigit(it)){
                currno=currno*10+(it-'0');
            }
            else if(it=='['){
                inst.push(currno);
                ststring.push(currstr);
                currno=0;
                currstr="";
            }
            else if(it==']'){
                int time=inst.top();
                inst.pop();
                string prev=ststring.top();
                ststring.pop();
                string ext="";
                for(int i=0;i<time;i++){
                    ext+=currstr;
                }
                currstr=prev+ext;


            }
            else{
               currstr.push_back(it); 
            }

        }
        return currstr;

    }
};