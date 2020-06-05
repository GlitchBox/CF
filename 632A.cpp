#include<bits/stdc++.h>

using namespace std;

int main(){
  int T;
  cin>>T;

  for(int cases=0;cases<T;cases++){

    int n,m;
    cin>>n>>m;
    int blockNo = n*m;
    for(int i=0;i<n-1;i++){
      if(i%2==0){
        for(int j=0;j<m;j++){
          if(j%2==0)
            cout<<"B";
          else
            cout<<"W";
        }
      }
      else{
        for(int j=0;j<m;j++){
          if(j%2==0)
            cout<<"W";
          else
            cout<<"B";
        }
      }
      cout<<endl;
    }

    if(blockNo%2==0){
      int i;
      for(i=0;i<=m/2;i++)
        cout<<"B";
      for(;i<m;i++)
        cout<<"W";
    }
    else{
      // if(n%2){
      //   for(int j=0;j<m;j++){
      //     if(j%2==0)
      //       cout<<"W";
      //     else
      //       cout<<"B";
      //   }
      // }
    //  else{
        for(int j=0;j<m;j++){
          if(j%2==0)
            cout<<"B";
          else
            cout<<"W";
        }
      //}
    }
    cout<<endl;

  }
}
