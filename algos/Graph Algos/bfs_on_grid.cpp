#include<bits/stdc++.h>
using namespace std;

const int mxN = 1e3;
int n, m;
int dist[mxN+1][mxN+1];
int vis[mxN+1][mxN+1];

bool isValid(int x, int y) {
    if(x<1 || x>n || y<1 || y>m) return false;
    if(vis[x][y]) return false;
    return true;
}

int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

void bfs(int srcx, int srcy) {
    queue<pair<int, int>> q;
    q.push({srcx, srcy});
    vis[srcx][srcy] = 1;
    dist[srcx][srcy] = 0;

    while(!q.empty()) {
        int currx = q.front().first;
        int curry = q.front().second;
        q.pop();
        for(int i=0; i<4; ++i) {
            if(isValid(currx+dx[i], curry+dy[i])) {
                int newx = currx+dx[i];
                int newy = curry+dy[i];
                q.push({newx, newy});
                vis[newx][newy] = 1;
                dist[newx][newy] = dist[currx][curry]+1;
            }
        }
    }
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j)
            cout << dist[i][j] << " ";
        cout << "\n";
    }
}

int main() {
    cin >> n >> m;
    int x, y;
    cin >> x >> y;
    bfs(x, y);
    return 0;
}
