//this sieve is valid for upto 10^7 in 1 sec
#include<bits/stdc++.h>
using namespace std;

int a[100000000];

int main() {
    int N=10000000;
    a[0] = a[1] = 1;
    int limit = sqrt(N);
    for(int i=4; i<=N; i+=2) a[i] = 1;
    for(int i=3; i<=limit; i+=2) {
        if(a[i]==0) {
            for(int j=i*i; j<=N; j += i)
                a[j] = 1;
        }
    }
    int cnt = 0;
    for(int i=0; i<=100; ++i) if(a[i]==0) cout << i << endl;
    cout << cnt;
    return 0;
}
