#include<bits/stdc++.h>
using namespace std;

/*  using recursive(slow)

int fibo(int n) {
    if(n==0 || n==1) return n;
    return fibo(n-1)+fibo(n-2);
}


int main() {
    int n; 
    cin >> n;
    cout << fibo(n) << "\n";
    return 0;
}

*/

int main() {
    int n;
    cin >> n;
    /* iterative method
    int a, b, c;
    b=0,c=0,a=1;
    while(n--) {
        cout << a << " ";
        b = c;
        c = a;
        a = b+c;
    }
    */
    
    // dynamic method

    int a[n+2];
    a[0] = 0, a[1] = 1;
    for(int i=2; i<=n; ++i) {
        a[i] = a[i-1]+a[i-2];
    }
    for(int i=1; i<=n; ++i) cout << a[i] << " ";
    return 0;
}
