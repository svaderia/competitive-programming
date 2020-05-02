class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = (int)nums.size();
        multiset<int> S;
        // vector<int> pref(n+1);
        int pref= 0;
        S.insert(0);
        int ans = 0;
        for(int i = 0; i < n; i++){
            pref += nums[i];
            int find_val = pref - k;
            ans += S.count(find_val);
            S.insert(pref);
        }
        return ans;
    }
};