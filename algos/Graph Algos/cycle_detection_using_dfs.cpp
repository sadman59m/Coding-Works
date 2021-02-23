#include<bits/stdc++.h>
using namespace std;

const int mxN=1e5;

int vis[mxN];
vector<int> v[mxN];

bool dfs(int node, int par) {
    vis[node] = 1;
    for(int x: v[node]) {
        if(vis[x]==0) {
            if(dfs(x, node)==true)
                return true;
        }
        else {
            if(x!=par)
                return true;
        }
    }
    return false;
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
    bool cycle=false;
    cycle = dfs(1, 1);
    if(cycle) cout << "cycle exist!";
    else cout << "no cycle exist!";
    return 0;
}
