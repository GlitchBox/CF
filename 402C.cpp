#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define ppi pair< pair<int,int>,int>
#define maxSize 200010
#define picked -1
using namespace std;

int now[maxSize];
int after[maxSize];
vector<pii> diff;

ll leastCost(int n, int k);

int main(){

    int n,k;
    cin>>n>>k;

    for(int i=0;i<n;i++)
        cin>>now[i];
    for(int i=0;i<n;i++)
        cin>>after[i];

    for(int i=0;i<n;i++)
        diff.push_back(make_pair(now[i]-after[i], i));

    sort(diff.begin(), diff.end());
    /*for(int i=0;i<n;i++)
        cout<<diff[i].first<<" "<<diff[i].second<<endl;*/

    cout<<leastCost(n,k)<<endl;
}

ll leastCost(int n, int k){

    ll cost = 0;

    //let's pick k items
    for(int i=0;i<k;i++){
        cost += now[diff[i].second];
        after[diff[i].second] = picked;
    }

    //look if there are more products for which current prices are lower than future prices
    for(int i=k;i<n;i++){
        if(diff[i].first<0){
            cost += now[diff[i].second];
            after[diff[i].second] = picked;
        }
    }

    //buy products one week later
    for(int i=0;i<n;i++){
        if(after[i] != picked)
            cost += after[i];
    }

    return cost;

}
