#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,res,i=0;
    string s;
    cin>>n;
    res = n;
    cin>>s;

    while(i<n-1)
    {
        if((s[i]=='R' && s[i+1]=='U')||(s[i]=='U' && s[i+1]=='R'))
        {
            //cout<<i<<"---"<<res<<endl;
            res -= 1;
            //cout<<i<<" "<<res<<endl;
            i+=2;
        }

        else
            i++;
    }

    cout<<res<<endl;
}
