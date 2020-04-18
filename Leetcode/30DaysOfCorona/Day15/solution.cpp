class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = (int) nums.size();
        vector<int> out(n);
        int pref = 1;
        for(int i = 0; i < n; i++){
            out[i] = pref;
            pref *= nums[i];
        }
        int suf = 1;
        for(int i = n - 1; i >= 0; i--){
            out[i] *= suf;
            suf *= nums[i];
        }
        return out;
    }
};