#include<bits/stdc++.h> 
using namespace std;
multiset<int> minHeap;
multiset<int, greater<int>> maxHeap;

int n, k;

void balance() {
    int cmp = maxHeap.size()-minHeap.size();
    if(cmp>=0 && cmp<=1) return;
    if(cmp<0) {
        int element = *minHeap.begin();
        minHeap.erase(minHeap.begin());
        maxHeap.insert(element);
        cmp=maxHeap.size() - minHeap.size();
    }
    else {
        int element = *maxHeap.begin();
        maxHeap.erase(maxHeap.begin());
        minHeap.insert(element);
        cmp = maxHeap.size() - minHeap.size();
    }
}

void add(int element) {
    if(maxHeap.empty()) {
        maxHeap.insert(element);
        return;
    }
    if(element > *maxHeap.begin())
        minHeap.insert(element);
    else
        maxHeap.insert(element);
    balance();
}
void rem(int element) {
    if(maxHeap.count(element) > 0) maxHeap.erase(maxHeap.find(element));
    else minHeap.erase(minHeap.find(element));

    balance();
}

int main() {
    cin >> n >> k;
    int ans=0;
    int a[n+1] = {0};
    for(int i=0; i<n; ++i) cin >> a[i];
    for(int i=0; i<k-1; ++i) add(a[i]);
    for(int i=k-1; i<n; ++i) {
        add(a[i]);
        double median;
        if(k&1) median = *maxHeap.begin();
        else median = (*maxHeap.begin() + *minHeap.begin())/2.0;
        cout << median << " ";
        rem(a[i-k+1]);
    }
    return 0;
}
