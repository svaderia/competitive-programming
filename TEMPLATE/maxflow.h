struct Edge{
    int to, cap, flow, id;
    Edge(int ii, int ww, int idx) : to(ii), cap(ww), flow(0), id(idx) {}
};

struct Graph{
    int n, m;
    vector<Edge> edges;
    vvi adj;

    Graph() : n(0), m(0), adj(0) {}
    Graph(int nn) : n(nn), m(0), adj(nn) {}

    void addEdge(int u, int v, int w){
        edges.pb(Edge(v, w, m));
        adj[u].pb(m);
        edges.pb(Edge(u, 0, m + 1));
        adj[v].pb(m + 1);
        m += 2;
    }

    void augment(int id, int flow){
        edges[id].flow += flow;
        edges[id ^ 1].flow -= flow;
    }
};

struct Maxflow{
    int n, s, t;
    Graph g;
    vi level, next;

    Maxflow() {}
    Maxflow(int nn, int ss, int tt, Graph gg) : n(nn), s(ss), t(tt), g(gg), level(n, -1) {}

    int solve(){
        int flow = 0;
        while(bfs()){
            next.clear(), next.rsz(n, 0);
            for(int f = dfs(s, INF); f != 0; f = dfs(s, INF)){
                flow += f;
            }
        }

        return flow;
    }

    bool bfs(){
        level.clear(), level.rsz(n, -1);
        queue<int> q;
        q.push(s);
        level[s] = 0;
        while(!q.empty()){
            int root = q.front();
            q.pop();
            for(auto id : g.adj[root]){
                int v = g.edges[id].to;
                int cap = g.edges[id].cap - g.edges[id].flow;
                if(level[v] == -1 && cap > 0){
                    level[v] = level[root] + 1;
                    q.push(v);
                }
            }
        }

        return level[t] != -1;
    }

    int dfs(int root, int flow){
        if(root == t) return flow;
        int totalEdges = sz(g.adj[root]);

        for(int &cid = next[root]; cid < totalEdges; cid++){
            int id = g.adj[root][cid];
            Edge &e = g.edges[id];
            int v = e.to;
            int cap = e.cap - e.flow;
            if(level[v] > level[root] && cap > 0){
                int blocking = dfs(v, min(cap, flow));

                if(blocking > 0){
                    g.augment(id, blocking);
                    return blocking;
                }
            }
        }
        return 0;
    }
};
