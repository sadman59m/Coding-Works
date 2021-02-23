#include<bits/stdc++.h>
using namespace std;

vector<int> ar[1001];
vector<int> tr[1001];
int vis[1001];
vector<int> scc;
vector<int> order;

void dfs(int src) {
    vis[src] = 1;
    for(int child: ar[src]) {
        if(vis[child]==0) {
            dfs(child);
        }
    }
    order.push_back(src);
}
void dfs1(int src) {
    vis[src] = 1;
    for(int child: tr[src]) {
        if(vis[child]==0) dfs1(child);
    }
    scc.push_back(src);
}

int main() {
    int n, m; 
    cin >> n >> m;
    for(int i=1; i<=m; ++i) {
        int x, y;
        cin >> x >> y;
        ar[x].push_back(y);
        tr[y].push_back(x);
    }
    for(int i=1; i<=n; ++i) {
        if(vis[i]==0) dfs(i);
    }
    for(int i=1; i<=n; ++i) vis[i] = 0;

    for(int i=1; i<=n; ++i) {
        if(vis[order[n-i]]==0) {
            scc.clear();
            dfs1(order[n-i]);
            for(int x: scc) cout << x << " ";
            cout << endl;
        }
    }
    return 0;
}
