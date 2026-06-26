class BrowserHistory {
public:
    stack<string> backk;
    stack<string> forw;
    string curr;

    BrowserHistory(string homepage) {
        curr = homepage;
    }
    
    void visit(string url) {
        backk.push(curr);
        curr = url;
        forw = stack<string>();
    }
    
    string back(int steps) {
        while(steps > 0 && !backk.empty()){
            forw.push(curr);
            curr = backk.top();
            backk.pop();
            steps--;
        }
        return curr;
    }
    
    string forward(int steps) {
         while(steps > 0 && !forw.empty()){
            backk.push(curr);
            curr = forw.top();
            forw.pop();
            steps--;
        }
        return curr;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->backk(steps);
 * string param_3 = obj->forward(steps);
 */