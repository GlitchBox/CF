#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;

string s;
int n;

pii ifDiverse(){

    pii ret = pii(-1,-1);

    for(int i=0;i<n-1;i++)
    {
        if(s[i] != s[i+1])
        {
            ret = pii(i,i+1);
            break;
        }
    }

    return ret;
}

int main(){

    cin>>n;
    cin>>s;

    pii ret = ifDiverse();

    if(ret.first == -1)
    {
        cout<<"NO"<<endl;
    }

    else{
        cout<<"YES"<<endl;
        cout<<s[ret.first]<<s[ret.second]<<endl;
    }
}
