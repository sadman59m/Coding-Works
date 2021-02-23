#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll binExp(ll base, ll power) {
    if(power<=0) return 1;
    ll tmp = binExp(base, power/2);
    ll res = tmp*tmp;
    if(power&1) res *= base;
    return res;
}

int main() {
    ll base, power;
    cin >> base >> power;
    ll ans = binExp(base, power);
    cout << ans;
}
//using iterator -> faster than recursion   
/* for mudulo add %M ---- for non modulo remove %M
 ll binExp(ll base, ll power) {
    ll res = 1;
    if(power==0) return 1;
    while(power>0) {
        if(power&1)
            res = (res*base)%M;
        base = (base*base)%M;
        power /= 2;
    }
    return res;
 }
 */
