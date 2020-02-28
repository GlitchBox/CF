#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll N,M,K,L;

int main(){

    cin>>N>>M>>K>>L;

    ll each = (N/M)*M;

   // if(each - K >=L)
       // cout<<1<<endl;
    //else if(each + K <= N) && each>=K)
       // cout<<1<<endl;
     if(each>=L && N-K>=L)
     cout<<1<<endl;


    else
        cout<<-1<<endl;
}
