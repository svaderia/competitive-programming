class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        
        int ans = 0;
        int mask = 0;
        for(int i = 0; i < 31; i++){
            int t = 1 << i;
            // cout << "t " << t;
            // cout << " mask " << mask << " ";
            // cout << "M " << m << " ";
            int curr = m & mask;
            // cout << "c " << curr << " ";
            // cout << "t & m " << (t & m) << endl;
            if(((t & m) > 0) && (curr + (n - m)) < t){
                ans += t;
            }
            mask += t;
        }
        return ans;
    }
};