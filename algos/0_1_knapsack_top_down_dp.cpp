#include<bits/stdc++.h>
using namespace std;

const int mxE=1e5;
int n, x;
array<int, 2> w[mxE];

int main() {
    cin >> n >> x;
    int dp[n+1][x+1];
    memset(dp, 0, sizeof(dp));
    for(int i=1; i<=n; ++i) cin >> w[i][0];
    for(int i=1; i<=n; ++i) cin >> w[i][1];
    sort(w, w+(n+1));
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=x; ++j) {
            if(j>=w[i][0]) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i][0]]+w[i][1]);
            }
            else
                dp[i][j] = dp[i-1][j];
    }
    }
    for(int i=1; i<=n; ++i)  cout << w[i][0] << " " << w[i][1] << endl;
    for(int i=0; i<=n; ++i) {
        for(int j=0; j<=x; ++j)
            cout << dp[i][j] << " " ;
        cout << endl;
    }
    cout << dp[n][x] << endl;
    return 0;
}
