#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll a[100010];

int main(){
  int n;
  cin>>n;

  for(int i=0;i<n;i++)
    cin>>a[i];

  int count = 0;
  for(int i=0;i<n;i++){
    if(a[i])
      count++;
    ll total = a[i];
    for(int j=i+1;j<n;j++){
      if(total+a[j]){
          count++;
          total += a[j];
      }
      else
        break;
    }
  }
  cout<<count<<endl;

}
