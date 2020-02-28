#include<bits/stdc++.h>

using namespace std;

int problemList[200];
int n,k;

int RecurseFind(int l, int r){

  if(l==r){
    if(problemList[l]<=k)
      return 1;
    return 0;
  }

  int ret = 0;
  int retLeft = 0, retRight = 0;

  if(problemList[l]<=k)
    retLeft = 1 + RecurseFind(l+1,r);
  if(problemList[r]<=k)
    retRight = 1+ RecurseFind(l,r-1);

  ret = max(retLeft,retRight);

  return ret;

}

int main(){

  cin>>n>>k;

  for(int i=0;i<n;i++){
    cin>>problemList[i];
  }

  int res = RecurseFind(0,n-1);

  printf("%d\n",res);

}
