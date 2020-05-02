class Solution {
public:
    bool canJump(vector<int>& nums) {
        int N = (int) nums.size();
        int maxJump = 1;
        for (int i = 0; i < N; i++){
           if ( maxJump > i){
               maxJump = max( maxJump, nums[i] + i + 1);

           }else{
               break;
               
           }
        }
        
        return maxJump >= N;
           


    }
};