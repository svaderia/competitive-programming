struct Tarjan{
    Graph g;
    vi pre, low, id;
    int numSCCs, preCounter;
    stack<int> stk;

    Tarjan(Graph gg) : g(gg), pre(g.n, -1), low(g.n), id(g.n), numSCCs(0), preCounter(0) {
        rep(i, g.n)
            if(pre[i] == -1)
                dfs(i);
    };

    void dfs(int root){
        pre[root] = low[root] = preCounter++;
        stk.push(root);

        for(auto edge : g.adj[root]){
            int child = edge.to;
            if(pre[child] == -1)
                dfs(child);

            low[root] = min(low[root], low[child]);
        }

        if(pre[root] == low[root]){
            while(true){
                int top = stk.top(); stk.pop();
                id[top] = numSCCs;
                low[top] = INF;

                if(top == root) break;
            }
            numSCCs++;
        }
    }
};
