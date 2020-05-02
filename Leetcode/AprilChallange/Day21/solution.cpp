/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int N, M;
    int binary_search(BinaryMatrix &binaryMatrix, int row){
        int l = 0;
        int r = M;
        while(l < r){
            int mid = l + (r - l)/2;
            int val = binaryMatrix.get(row, mid);
            if(val < 1){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return l;
    }
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int ans = INT_MAX;
        vector<int> v = binaryMatrix.dimensions();
        N = v[0]; M = v[1];
        
        for(int row = 0; row < N; row++){
            ans = min(ans, binary_search(binaryMatrix, row));
        }
        if(ans >= M){
            ans = -1;
        }
        return ans;
    }
};