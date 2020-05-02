class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int place = 0;
        int n = nums.size();
        cout << n;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                place++;
            }else{
                nums[i - place] = nums[i];
            }
        }
        for(int i = n - place; i < n; i++){
            nums[i] = 0;
        }
    }
};