#include<bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin>>n;

    int rem = n%4;

    if(!rem || rem == 3)
        cout<<0<<endl;
    else
        cout<<1<<endl;
}
