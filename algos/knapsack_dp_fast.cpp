#include<bits/stdc++.h>
using namespace std;

bitset<100000>can;

int main() {
    int n, w;
    cin >> n >> w;
    can[0] = 1;
    for(int idx=0; idx<n; ++idx) {
        int x;
        cin >> x;
        can |= can>>x;  // if can = 1000100000 and x= 8
                        //then can>>x means 1000100000000000000 = 0---4--------------
                        //                          10001000000 = 0-------8---12-----
                        //final can|=can>>x 1000100010001000000 = 0---4---8----12----
    }
    puts(can[w] ? "yes" : "no" );
    return 0;
}
