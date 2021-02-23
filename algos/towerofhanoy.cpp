#include<bits/stdc++.h>
using namespace std;

void hanoiTower(int n, char A, char C, char B) {           //A source, C destination , B medium             
    if(n==1) {
        cout << "Disk " << n << " from " << A << " to " << C << "\n";
        return;
    }
    hanoiTower(n-1, A, B, C);
        cout << "Disk " << n <<  " from " << A << " to " << C << "\n";
        hanoiTower(n-1, B, C, A);
}

int main() {
    int n;
    cin >> n;
    hanoiTower(n, 'A', 'C', 'B');
    return 0;
}
