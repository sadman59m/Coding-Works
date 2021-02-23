#include<bits/stdc++.h>
using namespace std;

//template<typename T>

void bfs_graph(int n) {
    map<int, list<int>> l;
    for(int i=0; i<n; ++i) {
        int x, y;
        cin >> x >> y;
        l[x].push_back(y);
        l[y].push_back(x);
    }
    map<int, bool> visited;
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << endl;
        for(int x: l[node]) {
            if(!visited[x]) {
                q.push(x);
                visited[x]=true;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    bfs_graph(n);
    return 0;
}
