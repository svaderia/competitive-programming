class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int sum = 0;
        for(auto x : shift){
            sum += (x[0] == 0 ? -1 * x[1] : x[1]);
        }
        int n = (int) s.size();
        while(sum + n < 0){
            sum += n;
        }
        vector<char> s1(n);
        for(int i = 0; i < n; i++){
            int next = i + sum + n;
            next %= n;
            s1[next] = s[i];
        }
        int i = 0;
        for(auto x : s1){
            s[i] = x;
            i++;
        }
        return s;
    }
};