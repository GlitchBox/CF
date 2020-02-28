#include<bits/stdc++.h>
using namespace std;

int main(){

  int n, a, b;
  cin>>n;

  for(int i=0;i<n;i++){
    cin>>a>>b;

    if(a==b)
      cout<<0<<endl;
    else if(a<b){
      int diff = b - a;
      if(diff%2)
        cout<<1<<endl;
      else
        cout<<2<<endl;
    }
    else{
      int diff = a - b;
      if(diff%2)
        cout<<2<<endl;
      else
        cout<<1<<endl;
    }
  }
}
