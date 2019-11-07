#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000
#define maxSize 100010
#define pll pair<ll, ll>
using namespace std;

ll a[maxSize], b[maxSize];
vector<pll> c;

bool sortDecOrder(const pll &a, const pll &b);
ll leastDiss(int n);

int main(){

    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        c.push_back(make_pair(a[i]-b[i], i));
    }

    cout<<leastDiss(n);

}

ll leastDiss(int n){

    sort(c.begin(), c.end(), sortDecOrder);
    ll cost = 0;

    for(int i=0;i<n;i++){

        int prevIndex = c[i].second;
        cost += (a[prevIndex]*i + b[prevIndex]*(n - i -1));
    }

    return cost;

}

bool sortDecOrder(const pll &a, const pll &b){

    return (a.first>b.first); //if you're the larger one, stay in front
    // return (a.first<b.first); //if you're the smaller one, stay in front
}
