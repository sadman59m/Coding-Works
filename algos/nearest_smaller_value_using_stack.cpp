#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; ++i) cin >> a[i];
    vector<int> v;
    stack<int> s;
    for(int i=0; i<n; ++i) {
        if(s.empty()) v.push_back(-1);
        else if(!s.empty() && a[s.top()]<a[i]) v.push_back(s.top());
        else if(!s.empty() && a[s.top()]>=a[i]) {
            while(!s.empty() && a[s.top()]>=a[i]) s.pop();
            if(s.empty()) v.push_back(-1);
            else v.push_back(s.top());
        }
        s.push(i);
    }
    for(int x: v) cout << x+1 << " ";
    return 0;
}
