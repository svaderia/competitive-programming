typedef long long int lli;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        lli max_sum = INT_MIN;
        lli sum = 0;
        for(auto x : nums){
           sum += x;
           max_sum = max(max_sum, sum);
           if(sum < 0){
                sum = 0;
           }
       } 
       
       return max_sum;
        
    }
};