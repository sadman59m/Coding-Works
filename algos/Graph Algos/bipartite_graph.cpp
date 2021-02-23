#include<bits/stdc++.h>
using namespace std;

const int mxN=1e5;

int vis[mxN+1];
int col[mxN+1];
vector<int> v[mxN+1];

bool dfs(int node, int c) {
    vis[node] = 1;
    col[node] = c;
    for(int x: v[node]) {
        if(vis[x]==0) {
            if(dfs(x, c^1)==false)
                return false;
        }
        else {
            if(col[node]==col[x])
                return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bool ans = dfs(1, 0);
    if(ans) cout << "bipartite";
    else cout << "not bipartite";
    return 0;
}
