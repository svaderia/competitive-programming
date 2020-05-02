class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, int> mp;
        int curr = 0;
        vector<vector<string>> ans;
        for(auto &x : strs){
            string y = x;
            sort(y.begin(), y.end());
            if(mp.find(y) != mp.end()){
                ans[mp[y]].push_back(x);
            }else{
                mp.insert({y, curr++});
                ans.push_back({x});
            }
        }
        return ans;
    }
}; 