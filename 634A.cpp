#include<bits/stdc++.h>
using namespace std;

int main(){

  int T,n;
  cin>>T;

  while(T>0){

    cin>>n;

    if(n==1 || n==2)
      cout<<0<<endl;
    else if(n%2)
      cout<<n/2<<endl;
    else
      cout<<(n/2)-1<<endl;
    T--;
  }
}
