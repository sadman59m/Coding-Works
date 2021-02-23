#include<bits/stdc++.h>
using namespace std;

int ans;
string s[8];
bool col[15], d1[15], d2[15];
void solve(int r) {
    if(r==8) {
        ++ans;
        return;
    }
    for(int c=0; c<8; ++c) {
        if(s[r][c]=='.') {
        if(!col[c]) {
            if(!d1[r-c+7] && !d2[r+c]) {
                col[c]=1, d1[r-c+7]=1, d2[r+c]=1;
                solve(r+1);
                col[c]=0, d1[r-c+7]=0, d2[r+c]=0;
            }
        }
        }
    }
}
int main() {
    for(int i=0; i<8; ++i) cin>> s[i];
    solve(0);
    cout << ans << "\n";
    return 0;
}
