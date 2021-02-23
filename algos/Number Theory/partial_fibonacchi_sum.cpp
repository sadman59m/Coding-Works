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

ll fib(ll m, ll n) {
    m %= 60;
    n %= 120;
    ll f[n];
    f[0]=0;
    f[1]=1;
    for(int i=2; i<=n; ++i) f[i] = (f[i-1]+f[i-2])%10;
    ll sum=0;
    for(int i=m; i<=n; ++i) sum += f[i]%10;
    return sum%10;

}
int main()
{
    ll n, m;
    cin >> m >> n;
    cout << fib(m, n) << endl;
    return 0;
}
