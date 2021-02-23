#include<bits/stdc++.h>
using namespace std;

vector<int> ar[100];
vector<int> res;
int in[100];

void khan(int n) {
    queue<int> q;
    for(int i=0; i<n; ++i) {
        if(in[i]==0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int curr = q.front();
        res.push_back(curr);
        q.pop();
        for(int node: ar[curr]) {
            --in[node];
            if(in[node]==0) {
                q.push(node);
            }
        }
    }
    cout << "Top Sort\n";
    for(int node: res)
        cout << node << " ";
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=m; ++i) {
        int a, b;
        cin >> a >> b;
        ar[a].push_back(b);
        ++in[b];
    }
    khan(n);
    return 0;
}
