#include<bits/stdc++.h>
typedef long long ll;

using namespace std;

ll pichano_p(ll n, ll m) {
    ll p=0;
    ll c=1;
    ll tmp;
    ll i=0;
    while(1) {
        tmp=p%m;
        p=c%m;
        c = (tmp+p)%m;
        ++i;
        if(c==1 && p==0) break;
    }
    return i;
}

ll fib(ll n, ll m) {
    ll pp = pichano_p(n, m);
    n%=pp;
    ll f[n];
    f[0]=0;
    f[1]=1;
    for(int i=2; i<=n; ++i) {
        f[i] = (f[i-1]%m + f[i-2]%m)%m;
    }
    return f[n]%m;
}
int main()
{
    ll n, m;
    cin >> n >> m;
    cout << fib(n, m) << endl;
    return 0;
}
