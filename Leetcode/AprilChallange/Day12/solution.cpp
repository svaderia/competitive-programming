class Solution {
public:
    priority_queue<int> max;
    int lastStoneWeight(vector<int>& stones) {
        for(auto x : stones){
            max.push(x);
        }
        while(max.size() > 1){
            int x = max.top();
            max.pop();
            int y = max.top();
            max.pop();
            x -= y;
            if(x > 0){
                max.push(x);
            }
        }
        if(max.size() == 1){
            return max.top();
        }else{
            return 0;
        }
    }
};