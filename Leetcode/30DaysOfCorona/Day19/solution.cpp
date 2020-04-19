class Solution {
public:
    int smallest_binary(vector<int> &nums, int target){
        int l = 0;
        int r = (int) nums.size();
        while(l < r){
            int mid = l + (r - l) / 2;
            if(nums[mid] < target){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return l;
    }
    
    int binary(vector<int> & nums, int l, int r, int target){
        while(l < r){
            int mid = l + (r - l) / 2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid] < target){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int N = (int) nums.size();
        if(N == 0){
            return -1;
        }
        int pivot = smallest_binary(nums, nums[0]);
        if(pivot == N){
            pivot = 0;
        }
        int l1 = binary(nums, 0, pivot, target);
        int l2 = binary(nums, pivot, N, target);
        return max(l1, l2);
    }
};