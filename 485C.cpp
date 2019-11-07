#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define inf 1000000000
#define maxSize 3010
using namespace std;

int n, font[maxSize], cost[maxSize], dp[maxSize][4][maxSize];

ll leastCost(int signNo, int signTaken, int lastFontSize);

int main(){
    cin>>n;

    for(int i=0;i<n;i++)
        cin>>font[i];
    for(int i=0;i<n;i++)
        cin>>cost[i];

    cout<<leastCost(0,0,-1)<<endl;

}

ll leastCost(int signNo, int signTaken, int lastFont){

    if(dp[signNo][signTaken][lastFont] != 0)
        return dp[signNo][signTaken][lastFont];

    if(signTaken == 3)
        return 0;
    if(signNo == n+1)
        return -1;

    ll ret1 = -1, ret2 = -1;

    if(lastFont == -1||(font[lastFont]<font[signNo])){

        ll temp = leastCost(signNo + 1, signTaken + 1, signNo);

        if(temp != -1)
            ret1 = cost[signNo] + temp;
    }
    ret2 = leastCost(signNo + 1, signTaken, lastFont);

    if(ret1==-1 && ret2 != -1)
        return dp[signNo][signTaken][lastFont] = ret2;
    if(ret1 != -1 && ret2 == -1)
        return dp[signNo][signTaken][lastFont] = ret1;

    if(ret1<ret2)
        return dp[signNo][signTaken][lastFont] = ret1;

    return dp[signNo][signTaken][lastFont] = ret2;


}
