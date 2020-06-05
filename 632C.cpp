#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll a[200010];
ll prefixSum[200010];


int main(){
  int n;
  cin>>n;

  prefixSum[0] = 0;
  for(int i=0;i<n;i++){
      cin>>a[i];
      prefixSum[i+1] = prefixSum[i] + a[i];
  }

  ll count = 0;
  set<ll> sums;
  sums.insert(0);
  int begin = 0, end = 0;
  while(begin<n){

    //prefixSum[1] contains the first element of the array a(a[0])
    while(end<n && !sums.count(prefixSum[end+1])){
      sums.insert(prefixSum[end+1]);
      end++;
    }

    //begin is the position previous to the position where the subset actually began
    //therefore 1 is not added to the following sum
    //sums always contains one element more than the subset under consideration actually contains
    //the value of the extra element is prefixSum[begin]
    count += (end-begin);
    sums.erase(prefixSum[begin]);
    begin++;

  }

  cout<<count<<endl;

}
