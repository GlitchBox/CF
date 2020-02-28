#include<bits/stdc++.h>
using namespace std;

int n;
string s;
int main()
{
    int howMany=0;
    cin>>n>>s;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='?')
        howMany++;
    }
    //cout<<howMany<<endl;
    for(int i=0;i<n-1;i++)
    {
        if(s[i]==s[i+1] && s[i] !='?')
        {
            cout<<"No"<<endl;
            return 0;
        }
    }

    if(s[0]=='?' || s[n-1]=='?')
    {
        cout<<"Yes"<<endl;
        return 0;
    }

    else if(howMany==0)
    {
        cout<<"No"<<endl;
        return 0;
    }

    else if(howMany == 1)
    {
        int k;
        for(k=0;k<n;k++)
        {
            if(s[k]=='?')
                break;
        }

        if(s[k-1] == s[k+1])
        {
            cout<<"Yes"<<endl;
        }

        else
            cout<<"No"<<endl;

            return 0;
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            if(s[i]=='?' && (s[i+1]=='?'||s[i-1]=='?'||s[i+1]==s[i-1]))
            {
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }

    cout<<"No"<<endl;

}
