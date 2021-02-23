#include<bits/stdc++.h>
using namespace std;

const int mxN=1e5;
vector<int> v[mxN+1];
int vis[mxN+1], low[mxN+1], in[mxN+1];
int timer;

void dfs(int node, int par) {
    vis[node] = 1;
    in[node] = low[node] = timer;
    ++timer;

    for(int child: v[node]) {
        if(child == par) continue;
        if(vis[child]) {
            //back edge
            low[node] = min(low[node], in[child]);
        }
        else {
            //forward edge
            dfs(child, node);
            if(low[child]>in[node])
                cout << node << " " << child << " is a bridge\n";
            low[node] = min(low[node], low[child]);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; ++i) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1, -1);
}
