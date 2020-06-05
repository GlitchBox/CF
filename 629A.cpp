#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main(){

  int T;
  cin>>T;

  while(T>0){
    ll a,b;
    cin>>a>>b;

    if(a>=b){
      ll rem = a%b;
      if(!rem)
        cout<<rem<<endl;
      else{
        ll mult = (a/b)+1;
        mult = mult*b;
        cout<<mult-a<<endl;
      }
    }

    else
      cout<<b-a<<endl;

    T--;
  }
}
