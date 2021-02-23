//fermat little theorem for checking probabilty of being a number prime
//formula a^(n-1) = 1 mod n, stands true for primes
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mulmod(ll a, ll b, ll c) {
    ll x=0, y=a%c;
    while(b>0) {
        if(b&1) x = (x+y)%c;
        y = (y*2LL)%c;
        b/=2;
    }
    return x%c;
}

ll binPow(ll b, ll p, ll m) {
    ll res = 1;
    while(p) {
        if(p&1) res = mulmod(res, b, m);
        b = mulmod(b, b, m);
        p /= 2;
    }
    return res;
}

bool fermat(ll n, ll iter = 5) {
    if(n<4)
        return n==2 || n==3;
    for(int i=0; i<iter; ++i) {
        ll a = 2 + rand()%(n-3);
        if(binPow(a, n-1, n) != 1)
            return false;
    }
    return true;
}

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        ll n;
        cin >> n;
        if(fermat(n)) cout << "YES\n";
        else cout << "NO\n";
    }
}
