#include<bits/stdc++.h>
using namespace std;

int T,L,v,l,r;
int main()
{
    cin>>T;

    for(int i=0;i<T;i++)
    {
        cin>>L>>v>>l>>r;

        cout<<(L/v) - (r/v) + ((l-1)/v)<<endl;
    }
}
