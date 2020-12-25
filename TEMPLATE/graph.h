struct Edge{
    int to, w, id;
    Edge(int ii, int ww, int idx) : to(ii), w(ww), id(idx) {}
};

struct Graph{
    int n, m;
    vector<vector<Edge>> adj;

    Graph() : n(0), m(0), adj(0) {}
    Graph(int nn) : n(nn), m(0), adj(nn) {}

    void addEdge(int u, int v, bool directed = false, int w = 0){
        adj[u].pb(Edge(v, w, m));
        if(!directed)
            adj[v].pb(Edge(u, w, m));
        m++;
    }
};
