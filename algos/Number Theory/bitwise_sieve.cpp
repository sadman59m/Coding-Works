#include<bits/stdc++.h>
using namespace std;

bool checkBit(int n, int pos) {
    return (bool)(n&(1<<pos));
}

int setVal(int n, int pos) {
    return n = n | (1<<pos);
}

int main() {
    int N=100;
    int status[N/32] = {0};
    cout << endl;
    status[0] = setVal(status[0], 0);
    status[0] = setVal(status[0], 1);
    for(int i=4; i<=N; i+=2) {
        status[i/32] = setVal(status[i/32], i%32);
    }
    for(int i=2; i*i<=N; ++i) {
        if(checkBit(status[3/32], i%32)==0) {
            for(int j=i*i; j<=N; j += i) {
                status[j/32] = setVal(status[j/32], j%32);
            }
        }
    }
    for(int i=1; i<=N; ++i) {
        if(checkBit(status[i/32], i%32)==0) cout << i << endl;
    }
}
