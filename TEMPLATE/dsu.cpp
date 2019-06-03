#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<lli> vli;
typedef vector<pii> vii;

#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define fill(a)  memset(a, 0, sizeof (a))
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define pb push_back

const int MAXN = 100005;
int id[MAXN];
int sz[MAXN];

int root(int p){
    while(p != id[p]){
        id[p] = id[id[p]];
        p = id[p];
    }
    return p;
}

void unite(int a, int b){
    int p1 = root(a);
    int p2 = root(b);
    if(p1 != p2){
        if(sz[p1] < sz[p2]){
            id[p1] = p2;
            sz[p2] += sz[p1];
        }else{
            id[p2] = p1;
            sz[p1] += sz[p2];
        }
    }
}

void init_dsu(int N){
    rep(i, N){
        id[i] = i;
        sz[i] = 1;
    }
}