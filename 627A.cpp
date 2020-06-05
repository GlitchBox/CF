#include<bits/stdc++.h>
using namespace std;

int arra[200];

int main(){
  int t,n;
  cin>>t;

  while(t){
    cin>>n;
    for(int i=0;i<n;i++){
      cin>>arra[i];
    }

    //find the max value of the array
    int maxVal = arra[0];
    for(int i=1;i<n;i++){
      if(maxVal<arra[i])
        maxVal = arra[i];
    }

    int f = 1;
    for(int i=0;i<n;i++){
      if((maxVal-arra[i])%2){
        cout<<"NO"<<endl;
        f=0;
        break;
      }
    }
    if(f)
      cout<<"YES"<<endl;

    t--;
  }
}
