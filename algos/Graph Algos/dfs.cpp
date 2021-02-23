#include<bits/stdc++.h>
using namespace std;

vector<int> v[10001];
int visited[10001];

void dfs(int a) {
    visited[a] = 1;
    cout << a << "->";
    for(int x: v[a]) {
        if(visited[x]==0)
            dfs(x);
    }
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
    dfs(1);
}
