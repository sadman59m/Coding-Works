#include<bits/stdc++.h>
using namespace std;

int findIdx(vector<int>& ar, int key) {
    int start=0;
    int end=ar.size();
    int l = ar.size();
    int middle;
    while(start<=end) {
        middle = (start+end)/2;
        if(middle<l && ar[middle]==key) return middle;
        else if(middle<l && ar[middle]<key && key<=ar[middle+1]) return middle+1;
        else if(ar[middle]<key) start = middle+1;
        else end = middle-1;
    }
    return -1;
}
int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; ++i) cin >> a[i];
    vector<int> v;
    v.push_back(a[0]);
    for(int i=1; i<n; ++i) {
        int len=v.size();
        if(a[i]<v[0]) v[0]=a[i];
        else if(a[i]>v[len-1]) v.push_back(a[i]);
        else {
            int idx = findIdx(v, a[i]);
            v[idx]=a[i];
        }
    }
    cout << v.size() << "\n";
    return 0;
}

