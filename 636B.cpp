#include<bits/stdc++.h>

using namespace std;

int main(){

  int T;
  cin>>T;

  while(T){

    int n;
    cin>>n;

    if((n/2)%2){
      cout<<"NO"<<endl;
    }
    else{
      int lim = n/2,lim2 = n/4;
      vector<int> res;

      for(int i=0, j=2;i<lim;i++, j+=2)
        res.push_back(j);

      for(int i=0;i<lim2;i++){
        res.push_back(res[i]-1);
      }
      for(int i=lim2;i<lim;i++){
        res.push_back(res[i]+1);
      }

      cout<<"YES"<<endl;
      for(int i=0;i<n;i++)
        cout<<res[i]<<" ";
      cout<<endl;

    }

    T--;
  }
}
