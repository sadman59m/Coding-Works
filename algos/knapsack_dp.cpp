//time complexity O(W*n) w=weight,n number of element
//dynamic procedure also subsum 
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, w;
    cin >> n >> w;
    int can[w+1] = {0};
    can[0] = 1;
    for(int idx=0; idx<n; ++idx) {
        int x;
        cin >> x;
        for(int i=w; i>=x; --i) {
            if(can[i-x]) can[i]=true;
        }
    }
    puts(can[w] ? "yes" : "no" );
    return 0;
}
