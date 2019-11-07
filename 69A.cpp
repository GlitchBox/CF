#include<bits/stdc++.h>

using namespace std;

int main(){
    int x=0,y=0,z=0,a,b,c,n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
        x += a;
        y += b;
        z += c;
    }

    if(!x && !y && !z)
        cout<<"YES\n";
    else
        cout<<"NO"<<endl;

}
