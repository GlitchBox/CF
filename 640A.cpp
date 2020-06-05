#include<bits/stdc++.h>
using namespace std;

int main(){
  int T;
  int n;

  cin>>T;
  while(T>0){

    cin>>n;
    int digitNum = (int)(log10(n)+1);
    int power = 1;
    for(int i=1;i<digitNum;i++)
      power *= 10;

    vector<int> ans;
    while(n){

      int rem = n%power;
      int ret = n - rem;
      if(ret)
        ans.push_back(ret);
      n = rem;

      int tempDigitNo = (int)(log10(n)+1);
      for(int j=0;j<digitNum-tempDigitNo;j++)
        power /= 10;
      digitNum = tempDigitNo;

    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
      cout<<ans[i]<<" ";
    cout<<endl;
    T--;
  }

}
