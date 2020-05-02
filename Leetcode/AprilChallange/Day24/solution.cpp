class LRUCache {
public:
    list<int> dq;
    map<int, list<int>::iterator> mp;
    map<int, int> valmap;
    int cap;
    
    LRUCache(int capacity) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        cap = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            dq.erase(mp[key]);
            dq.push_front(key);
            mp[key] = dq.begin();
            return valmap[key];
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key) == mp.end()){
            if((int)dq.size() == cap){
                int val = *dq.rbegin();
                dq.pop_back();
                mp.erase(val);
                valmap.erase(val);
            }
            dq.push_front(key);
            valmap[key] = value;
            mp[key] = dq.begin();
        }else{
            dq.erase(mp[key]);
            dq.push_front(key);
            mp[key] = dq.begin();
            valmap[key] = value;
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */