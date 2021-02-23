#include<bits/stdc++.h>
using namespace std;

const int mxN = 1e5;
vector<int> v[mxN+1];
int vis[mxN+1], onStack[mxN+1];
int in[mxN+1], low[mxN+1];
int scc, timer;
stack<int> st;

void dfs(int node) {
    vis[node] = 1;
    in[node] = low[node] = ++timer;
    st.push(node);
    onStack[node] = 1;
    for(int u: v[node]) {
        if(vis[u] && onStack[u]) low[node] = min(low[node], in[u]);
        if(vis[u] == 0) {
            dfs(u);
            if(onStack[u]) low[node] = min(low[node], low[u]);
        }
    }
    if(in[node]==low[node]) {
        ++scc;
        cout << scc << "\n";
        int u;
        while(1) {
            u = st.top();
            onStack[u] = 0;
            st.pop();
            cout << u << " ";
            if(u==node) {
                cout << "\n";
                break;
            }
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
    }
    for(int i=1; i<=n; ++i) vis[i]=0, onStack[i] = 0;
    for(int i=1; i<=n; ++i) {
        if(vis[i]==0) dfs(i);
    }
    return 0;
}
