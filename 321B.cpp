#include<bits/stdc++.h>
#define maxSize 100010
#define ll long long
#define pii pair<int, int>
using namespace std;

int factor[maxSize];
vector<pii> sortedMoney;
ll incrementalFactor[maxSize];

int upperLimit(int n, int targetMoney);
ll maxFriends(int n, int d);

bool comparator(pii a, pii b){
    return a.second<b.second;
}

int main(){

    int n,d,money;
    cin>>n>>d;

    for(int i=0;i<n;i++){
        cin>>money;
        cin>>factor[i];
        sortedMoney.push_back(pii(i,money));
    }

    sort(sortedMoney.begin(), sortedMoney.end(), comparator);

   /* for(int i=0;i<sortedMoney.size();i++)
        cout<<sortedMoney[i].first<<","<<sortedMoney[i].second<<endl; */
    cout<<maxFriends(n, d)<<endl;


}

int upperLimit(int n, int targetMoney){

    int lo = 0, hi = n-1, mid;

    while(lo<=hi){
        mid = (lo+hi)/2;

        if(targetMoney>=sortedMoney[mid].second)
            lo = mid + 1;
        else
            hi = mid - 1;
    }

    return hi;

}

ll maxFriends(int n, int d){

    incrementalFactor[0] = factor[sortedMoney[0].first];
    for(int i=1;i<n;i++){
        incrementalFactor[i] += (factor[sortedMoney[i].first] + incrementalFactor[i-1]);
    }

    /*for(int i=0;i<n;i++)
        cout<<incrementalFactor[i]<<endl;
    while(1);*/

    ll ret = -1;
    for(int i=0;i<n;){
        //cout<<"here"<<endl;
        ll temp = 0;
        int ul = upperLimit(n, sortedMoney[i].second+d-1);

        if(i)
            temp = incrementalFactor[ul] - incrementalFactor[i-1];
        else
            temp = incrementalFactor[ul];

        if(temp>ret)
            ret = temp;

        int j;
        for(j=i+1;j<n;j++){
            if(sortedMoney[j].second != sortedMoney[i].second)
                break;
        }
        i = j;
    }

    return ret;
}
