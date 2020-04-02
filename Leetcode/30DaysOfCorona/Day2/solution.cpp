#define rep(i, n)    for(int i = 0; i < (n); ++i)

class Solution {
    int first = true;
    int dp[811];
    bool visited[811];
    
private:
    int recur(int t){
        // cout << t << endl;
        if(dp[t] == -1){
            if(visited[t]){
                dp[t] = 0;
            }else{
                int t2 = t;
                int n = 0;
                while(t2 != 0){
                    n += (t2 % 10) * (t2 % 10);
                    t2 /= 10;
                }
                visited[t] = true;
                dp[t] = recur(n);
                visited[t] = false;
            }
        }
        return dp[t];
    }
    
private:
    void init(){
        if(first){
            rep(i, 811){
                dp[i] = -1;
                visited[i] = false;
            }
            dp[1] = 1;
            first = false;
        }
    }
public:
    bool isHappy(int n) {
        init();
        int t2 = n;
        int tot = 0;
        while(t2 != 0){
            tot += (t2 % 10) * (t2 % 10);
            t2 /= 10;
        }
        return recur(tot);
    }
};