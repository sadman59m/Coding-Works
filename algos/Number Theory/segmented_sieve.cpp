#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int const N=1e7, M=1e5;
ll l, r;

bool primes[N+2];
vector<ll> rangeprimes, segmentprimes;

int main() {
    cin >> l >> r;
    primes[0]=primes[1]=1;

    for(int i=4; i<=N; i+=2) primes[i] = 1;
    for(int i=3; i*i<=N; i+= 2) {
        if(primes[i]==0) {
            for(int j=i*i; j<=N; j+=2*i)
                primes[j] = 1;
        }
    }

    ll limit = (sqrt(r))+1;
    for(int i=l; i<=r; ++i) segmentprimes.push_back(i);
    if(l==1) segmentprimes[0]=0;
    if(l==0) segmentprimes[1]=0;

    for(int i=2; i<=limit; ++i) if(primes[i]==0) rangeprimes.push_back(i);
    for(int i=0; i<rangeprimes.size(); ++i) {
        ll cp = rangeprimes[i];
        ll start = cp*cp;
        if(start<l) start = ((l+cp-1)/cp)*cp;
        for(ll j=start; j<=r; j += cp)
            segmentprimes[j-l] = 0;
    }
    return 0;
}
