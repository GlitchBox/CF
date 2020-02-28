#include<bits/stdc++.h>
#define ll long long
#define maxSize 1000000
using namespace std;

ll events[maxSize], alarms[maxSize];
vector<ll> diff;

int main(){

    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        cin>>events[i];
    }
    for(int i=0;i<m;i++)
        cin>>alarms[i];

    for(int i=0;i<n-1;i++)
        diff.push_back(events[i+1] - events[i]);

    ll gcdOfDiff = 0;
    //cout<<__gcd(0,1);
    //while(1);

    for(int i=0;i<diff.size();i++)
        gcdOfDiff = __gcd(gcdOfDiff,diff[i]);

    //cout<<gcdOfDiff<<endl;

    for(int i=0;i<m;i++){

        if(gcdOfDiff==alarms[i] || (gcdOfDiff>alarms[i] && gcdOfDiff%alarms[i]==0)){
            cout<<"YES\n"<<events[0]<<" "<<i+1<<endl;
            return 0;
        }
    }

    cout<<"NO\n";

}
