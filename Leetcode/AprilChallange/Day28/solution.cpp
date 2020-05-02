class FirstUnique {
public:
    queue<int> q;
    map<int, int> count;
    
    FirstUnique(vector<int>& nums) {
        for(auto x : nums){
            count[x]++;
            if(count[x] == 1){
                q.push(x);
            }
        }
    }
    
    int showFirstUnique() {
        while(!q.empty() && count[q.front()] > 1){
            q.pop();
        }
        if(q.empty()){
            return -1;
        }else{
            return q.front();
        }
    }
    
    void add(int value) {
        count[value]++;
        if(count[value] == 1){
            q.push(value);
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */