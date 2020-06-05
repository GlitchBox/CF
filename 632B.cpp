#include<bits/stdc++.h>

using namespace std;

int a[100010], b[100010];

int main(){
  int T;
  cin>>T;

  for(int cases=0;cases<T;cases++){
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
      cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];

    if(a[0] != b[0]){
      cout<<"NO"<<endl;
    }
    else{
      int first1 = n+1, first1m = n+1;
      for(int i=0;i<n;i++){
        if(a[i]==-1){
            first1m = i;
            break;
        }
      }
      for(int i=0;i<n;i++){
        if( a[i]==1){
            first1 = i;
            break;
        }
      }
      // cout<<first1<<", "<<first1m<<endl;

      int poss = 1;
      for(int i=0;i<n;i++){
        if(b[i]>a[i] && first1>=i){
          poss = 0;
          break;
        }
        else if(b[i]<a[i] && first1m>=i){
          poss = 0;
          break;
        }
      }
      if(poss)
        cout<<"YES"<<endl;
      else
        cout<<"NO"<<endl;

    }

  }
}
