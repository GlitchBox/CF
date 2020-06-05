#include<bits/stdc++.h>

using namespace std;
int arra[100020];

int main(){
  int t,n;
  cin>>t;

  while(t>0){
    cin>>n;
    for(int i=0;i<n;i++){
      cin>>arra[i];
    }

    sort(arra, arra+n);
    int count=1, currentNum = arra[0];

    for(int i=1;i<n;i++){
      if(currentNum!=arra[i]){
        count++;
        currentNum = arra[i];
      }
    }
    cout<<count<<endl;

    t--;
  }
}
