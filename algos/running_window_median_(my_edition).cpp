#include<bits/stdc++.h>
using namespace std;

int n, k;
multiset<int> top;
multiset<int, greater<int>> bot;

void balance() {
    if(bot.size()==top.size() || bot.size()-1 == top.size()) return;
    if(top.size()>bot.size()) {
        int element = *top.begin();
        top.erase(top.begin());
        bot.insert(element);
    }
    else {
        int element = *bot.begin();
        bot.erase(bot.begin());
        top.insert(element);
    }
}

void add(int element) {
    if(bot.empty()) {
        bot.insert(element);
        return;
    }
    if(element > *bot.begin())
        top.insert(element);
    else
        bot.insert(element);
    balance();
}

void rem(int element) {
    if(element <= *bot.begin())
        bot.erase(bot.find(element));
    else 
        top.erase(top.find(element));
    balance();
}

int main() {
    cin >> n >> k;
    int a[n+1]={0};
    for(int i=0; i<n; ++i) cin >> a[i];
    for(int i=0; i<k-1; ++i) add(a[i]);
    for(int i=k-1; i<n; ++i) {
        add(a[i]);
        //if(bot.size()>top.size()) cout << *bot.begin() << endl;
        //else cout << *bot.begin() << " " << *top.begin() << endl;
        cout << *bot.begin() << " ";
        rem(a[i-k+1]);
    }
    return 0;
}
