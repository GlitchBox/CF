#include<bits/stdc++.h>
#define ll long long
#define maxSize 100010
using namespace std;

int chests[maxSize], keys[maxSize];

int main(){
    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        cin>>chests[i];
    }
    for(int i=0;i<m;i++){
        cin>>keys[i];
    }

    int odd1=0,even1=0,odd2=0,even2=0;
    for(int i=0;i<n;i++){
        if(chests[i]%2)
            odd1++;
        else
            even1++;
    }
    for(int i=0;i<m;i++){
        if(keys[i]%2)
            odd2++;
        else
            even2++;
    }

    cout<<min(even1,odd2)+min(even2,odd1)<<endl;

}
