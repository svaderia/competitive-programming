class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        map<int, int> my;
        int ans = 0;
        my[0] = -1;
        for(int i = 0; i < n; i++){
            sum += (nums[i] == 0 ? -1 : 1);
            if(my.count(sum)){
                ans = max(ans, i - my[sum]);
            }else{
                my[sum] = i;
            }
        }

        return ans;
    }
};