class Solution {
public:
    int countElements(vector<int>& arr) {
        map<int, int> mp;
        for(int x : arr){
            mp[x]++;
        }
        long long ans = 0;
        for(auto t : mp){
            if(mp.find(t.first + 1) != mp.end()){
                ans += t.second;
            }
        }
        return ans;
    }
};
