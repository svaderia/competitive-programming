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

void input(int N){

        vi vert[N];
        int x, y;
        rep(i, N - 1){
            cin >> x >> y;
            vert[x-1].push_back(y-1);
            vert[y-1].push_back(x-1);
        }

        queue<int> q;
        bool visited[N];
        fill(visited);
        q.push(0);

        vi fin_vert[N];

        while(!q.empty()){
            int top = q.front();
            q.pop();
            visited[top] = true;
            tr(vert[top], it){
                if(visited[*it] != true){
                    q.push(*it);
                    fin_vert[top].pb(*it);
                }
            }
        }
}