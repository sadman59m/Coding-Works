#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    int tmp[n];
    for(int i=0; i<n; ++i) tmp[i]=1;
    for(int i=0; i<n; ++i) cin >> a[i];
    for(int i=1; i<n; ++i) {
        for(int j=0; j<i; ++j) {
            if(a[j]<a[i])
                tmp[i]=max(tmp[i], tmp[j]+1);
        }
    }
    for(int x: tmp) cout << x << " ";
    cout << endl;
    int ans =0;
    for(int x: tmp) ans = max(x, ans);
    cout << ans << endl;
    return 0;
}
