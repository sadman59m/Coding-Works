#include<bits/stdc++.h>
using namespace std;

const int mxN = 1e5;
int vis[mxN+1], in[mxN+1], low[mxN+1];
vector<int> v[mxN+1];
int timer;
set<int> s;

void dfs(int node, int par) {
    vis[node] = 1;
    in[node]=low[node]=++timer;
    int children=0;
    for(int child: v[node]) {
        if(child==par) continue;
        if(vis[child]) low[node] = min(low[node], in[child]);
        else {
            dfs(child, node);
            ++children;
            low[node] = min(low[node], low[child]);
            if(low[child] >= in[node] && par != -1) s.insert(node);
        }
    }
    if(par == -1 && children>1) s.insert(node);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        for(int i=0; i<=mxN; ++i) {
            v[i].clear();
            vis[i]=in[i]=low[i]=0;
        }
        timer = 0;
        s.clear();
        for(int i=0; i<m; ++i) {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        for(int i=1; i<=n; ++i) {
            if(vis[i]==0) dfs(i, -1);
        }
        cout << s.size() << "\n";
    }
    return 0;
}
