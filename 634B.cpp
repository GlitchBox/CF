#include<bits/stdc++.h>

using namespace std;

int main(){
  int T;
  cin>>T;

  while(T){
    int n,a,b;
    string ret="";

    cin>>n>>a>>b;
    int repeatNo = min(a,b);
    for(int i=0,j=0;i<n;i++){
      ret.append(string(1,'a'+j));
      j = (j+1)%repeatNo;
    }
    cout<<ret<<endl;
    T--;
  }
}
