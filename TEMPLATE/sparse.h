// This way of doing it is only useful for RMQ types operations.
// More importantly this can only be used for idempotent functions. 
// For associative functions you would still need O(logN) time for slightly different query method.

template<typename T>
struct sparse_table{

    const int LOG = 20; // should be okay until 10^6 arrays

    T n;
    vector<vector<T> > dp;

    // this is the merge function
    // TODO: Something you might need to change
    T merge(T a, T b){
        return min(a, b);
    }

    sprase_table(vector<T> &a){
        n = sz(a);
        dp.resize(LOG);
        dp[0] = a;

        repA(id, 1, LOG - 1){
            dp[id].resize(n);
            rep(j, n){
                dp[id][j] = dp[id - 1][j];
                int next_id = j + (1L << (id - 1));
                if(next_id < n){
                    dp[id][j] = merge(dp[id][j], dp[id - 1][next_id]);
                }
            }
        }
    }

    // query of the form [l, r]
    T query(int l, int r){
        int d = r - l + 1;
        int id = 63 - __builtin_clzll(d); // if you remove the #define int lli, this will fail :)
        int shift = (1L << id);
        return merge(dp[id][l], dp[id][r - shift + 1]);
    }


};

