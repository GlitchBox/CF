#include<bits/stdc++.h>
#define ll long long
#define maxSize 100010
using namespace std;

int upperBound(int n, int target);

int prices[maxSize];

int main(){
    int n,q,x;
    cin>>n;

    for(int i=0;i<n;i++)
        cin>>prices[i];

    sort(prices, prices+n);
    cin>>q;

    for(int i=0;i<q;i++){
        cin>>x;
        cout<<upperBound(n,x)<<endl;
    }
}

int upperBound(int n, int target){

    int lo = 0, hi = n-1,mid;

    while(hi>=lo){

        mid = (hi+lo)/2;

        if(prices[mid]<=target)
            lo = mid + 1;
        else
            hi = mid - 1;
    }

    return lo;
}
