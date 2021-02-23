#include<bits/stdc++.h>
using namespace std;

void solve(int t) {
    if((t&1)^1) cout << "even \n";
    else cout << "odd \n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        solve(t);
    }
    return 0;
}
