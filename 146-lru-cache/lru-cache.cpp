class LRUCache {
public:
    
    list<int> dl;
    unordered_map<int, pair<list<int>::iterator, int>> mp;
    int n;

    LRUCache(int capacity) {
        n = capacity;
    }
    
    void solve(int key){
        dl.erase(mp[key].first);

        dl.push_front(key);

        mp[key].first = dl.begin();
    }

    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;

        solve(key);

        return mp[key].second;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            mp[key].second = value;
            solve(key);
        }else{
            dl.push_front(key);
            mp[key] = {dl.begin(), value};
            n--;
        }
        if(n < 0){
            int dlt = dl.back();
            mp.erase(dlt);
            dl.pop_back();
            n++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */