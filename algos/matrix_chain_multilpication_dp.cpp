#include<bits/stdc++.h>
using namespace std;
int n;

void printBrackets(int i, int j, vector<vector<int>> &brackets, char &name) {
    if(i == j) {
        cout << name;
        name++;
    }
    else {
        cout << "(";
        printBrackets(i, brackets[i][j], brackets, name);
        printBrackets(brackets[i][j]+1, j, brackets, name);
        cout << ")";
    }
}
int solve(vector<int> &a) {
    int dp[n][n];
    vector<vector<int>> brackets(n, vector<int>(n,0));
    for(int i=1; i<n; ++i)
        dp[i][i] = 0;
    for(int l=2; l<n; ++l) {
        for(int i=1; i< n-l+1; ++i) {
            int j=i+l-1;
            dp[i][j] = INT_MAX;
            for(int k=i; k<j; ++k) {
                int val = dp[i][k]+dp[k+1][j]+(a[i-1]*a[k]*a[j]);
                if(val<dp[i][j]) {
                    dp[i][j] = val;
                    brackets[i][j] = k;
                }
            }
        }
    }
    char name = 'A';
    printBrackets(1, n-1, brackets, name);
    cout << endl;
    return dp[1][n-1];
}

int main() {
    cin >> n;
    vector<int> v;
    for(int i=0; i<n; ++i) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    int ans = solve(v);
    cout << ans;
    return 0;
}
