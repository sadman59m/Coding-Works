//this rather test the probability of a number of being prime than confirming its prime
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mulmod(ll a, ll b, ll c) {
    ll x = 0, y = a%c;
    while(b>0) {
        if(b&1) x = (x+y)%c;
        y = (y*2LL)%c;
        b >>= 1;
    }
    return x%c;
}

ll binPow(ll b, ll p, ll m) {
    ll res = 1;
    while(p) {
        if(p&1) res = mulmod(res, b, m);
        b = mulmod(b, b, m);
        p  >>= 1;
    }
    return res;
}

bool checkComposite(ll a, ll n, ll d, ll s) {
    ll x = binPow(a, d, n);
    if(x==1 || x==n-1) return false;
    for(ll r=1; r<s; ++r) {
        x = mulmod(x, x, n);
        if(x == n-1) return false;
    }
    return true;
}

bool millerRabin(ll n, ll iter=5) {
    if(n<2) return false;
    ll d = n-1, s=0;
    while((d&1) == 0) {       // here d has to be add, and s is power of 2
        d >>= 1;
        ++s;
    }
    for(ll a: {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if(a==n) return true;
        if(checkComposite(a, n, d, s))
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
        if(millerRabin(n)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
