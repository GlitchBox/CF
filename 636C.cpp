#include<bits/stdc++.h>
#define ll long long
using namespace std;

int nums[200010];

int main(){

  int T;
  cin>>T;

  while(T){
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
      cin>>nums[i];

    ll ret = nums[0];
    int currentSign = 1;
    int currentNum = nums[0];

    if(ret<0)
      currentSign = -1;

    int index = 1;
    while(index<n){
      int nextSign = 1;
      if(nums[index]<0)
        nextSign = -1;

      if(currentSign == nextSign){
        if(nums[index]>currentNum){
            ret -= currentNum;
            currentNum = nums[index];
            ret += currentNum;
        }
      }
      else{
        currentNum = nums[index];
        ret += currentNum;
        currentSign *= -1;
      }

      index++;
    }
    cout<<ret<<endl;

    T--;
  }
}
