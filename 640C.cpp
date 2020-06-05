#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

  int T;
  cin>>T;
  while(T>0){
    ll n,k;
    cin>>n>>k;

    if(k<n){
        cout<<k<<endl;
    }
    else{
      k -= (n-1);
      //cout<<k<<endl;
      ll div = k/(n-1);
      if(k%(n-1)==0)
        div-=1;

      ll ans = n + n*div + (k - (n-1)*div);
      cout<<ans<<endl;
    }

    T--;
  }
}
