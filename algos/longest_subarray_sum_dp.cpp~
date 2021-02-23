#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long a[n];
    for(int i=0; i<n; ++i) cin >> a[i];
    long long globalsum=INT_MIN, currentsum=INT_MIN;
    for(int i=0; i<n; ++i) {
        currentsum = max(a[i], currentsum+a[i]);
        globalsum = max(currentsum, globalsum);
    }
    cout << globalsum << "\n";
    return 0;
}
