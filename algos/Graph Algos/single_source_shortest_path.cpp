#include<bits/stdc++.h>
using namespace std;

const int mxN=1e5;

int vis[mxN];
int dis[mxN];
vector<int>ar[mxN];

void dfs(int node, int d) {
    vis[node] = 1;
    dis[node] = d;
    for(int x:ar[node]) {
        if(!vis[x])
            dfs(x, dis[node]+1);
    }
}

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }
    dfs(1, 0);
    for(int i=1; i<=n; ++i)
        cout << dis[i] << " ";
}