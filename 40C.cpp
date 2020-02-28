#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n;
ll ara[200001];

ll maxElement()
{
    ll maxEl = ara[1];
    for(int i=2;i<=n;i++)
    {
        if(maxEl<ara[i])
            maxEl = ara[i];
    }
    return maxEl;
}


int main()
{
    cin>>n;

    ll colNo,rowNo,highestDiff=-1,largestElement,temp;
    for(int i=1;i<=n;i++)
        cin>>ara[i];
    if(n==1)
    {
        cout<<"YES"<<endl;
        cout<<1<<" "<<ara[1]<<endl;
        return 0;
    }


    for(int i=1;i<=n-1;i++)
    {
        temp = ara[i+1] - ara[i];
        if(temp<0)
            temp *=-1;
        if(temp>highestDiff)
        {
            highestDiff = temp;
            cout<<ara[i]<<","<<ara[i+1]<<endl;
        }

    }
    largestElement = maxElement();
    if(highestDiff == 1)
        colNo = largestElement;
    else
        colNo = highestDiff;

    rowNo = ceil(largestElement/(1.0*colNo));

    for(int i=1;i<=n-1;i++)
    {
        temp = ara[i+1] - ara[i];
        if(temp<0)
            temp *=-1;

        if((temp != 1 && temp != colNo )||(ara[i]==ara[i+1]))
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }

    cout<<"YES"<<endl;
    cout<<rowNo<<" "<<colNo<<endl;

}
