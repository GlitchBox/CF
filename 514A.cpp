#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,L,a;
ll t,l;

ll mostBreaks()
{

    ll numOfBreaks = 0;
    ll prevEnd = 0;

    //in this loop we deal with cases where he smokes before the first customer came and in between customer arrival
    //equation for calculation : (t - prevEnd)/a
    for(int i=0;i<n;i++)
    {
        cin>>t>>l;

        numOfBreaks += ((t - prevEnd)/a);
        prevEnd = t + l;
    }

    //the following chunk of code handles cases where he smokes after the last customer has left
    numOfBreaks += ((L - prevEnd)/a);

    return numOfBreaks;
}

int main()
{
    cin>>n>>L>>a;

    cout<<mostBreaks()<<endl;
}
