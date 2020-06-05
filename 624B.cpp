#include<bits/stdc++.h>
using namespace std;

int a[200], p[200];

bool ifSorted(int n, int m){

  int leftMax = 0;
  int currentMax = a[0];

  for(int i=1;i<n;i++){
    if(!p[i-1])
      leftMax = currentMax;

    if(leftMax>a[i])
      return false;

    currentMax = max(a[i],currentMax);
  }

  return true;
}

int main(){

  int t, m , n, temp;
  cin>>t;

  for(int i=0;i<t;i++){

      cin>>n>>m;
      for(int j=0;j<n;j++)
        p[j] = 0;

      for(int j=0;j<n;j++){
        cin>>a[j];
      }
      for(int j=0;j<m;j++){
        cin>>temp;
        p[temp-1]=1;
      }

     bool ret = ifSorted(n,m);
     if(ret)
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl; 

  }

}
