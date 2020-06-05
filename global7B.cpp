#include<bits/stdc++.h>
#define ll long long

using namespace std;
int numbers[200010];

int main(){

  int n;
  cin>>n;

  for(int i=0;i<n;i++)
    cin>>numbers[i];

  int maxNum = 0;
  for(int i=0;i<n;i++){
    numbers[i] += maxNum;
    maxNum = max(maxNum, numbers[i]);
  }

  for(int i=0;i<n;i++){
    cout<<numbers[i]<<" ";
  }
  cout<<endl;
}
