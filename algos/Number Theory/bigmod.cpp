#include<bits/stdc++.h>
using namespace std;

long long bigMod(long long n, long  long p, long long m) {
    
    if(p==0) return 1;
    long long c = bigMod(n, p/2, m);
    if(p&1) 
        return (((c*c)%m)*n)%m;
    
    return (c*c)%m;
}

int main()
{
    long long n, p, m;
    cin >> n >> p >> m;
    long long ans = bigMod(n, p, m);
    if(ans<0) ans += m;
    cout << ans << "\n";
    return 0;
}
