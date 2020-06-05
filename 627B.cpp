#include<bits/stdc++.h>

using namespace std;

int dp[5000][5000];
int arra[5000];

int main(){
  int t,n;
  cin>>t;

  for(int i=0;i<t;i++){
    cin>>n;

    for(int j=0;j<n;j++){
      cin>>arra[j];
    }

    for(int j=0;j<n;j++){
      for(int k=0;k<n;k++){
        dp[j][k] = 0;
      }
    }
    for(int j=0;j<n;j++){
      dp[j][j] = 1;
    }

    for(int len=1;len<n;len++){
        int b=0,e=b+len;
        //cout<<b<<" "<<e<<endl;
        while(e<n){
          if(arra[b]==arra[e])
            dp[b][e] = dp[b+1][e-1] + 2;
          else
            dp[b][e] = max(dp[b+1][e],dp[b][e-1]);

          b++;e++;
        }
    }

    // int f = 0;
    // for(int j=0;j<n;j++){
    //   for(int k=0;k<n;k++){
    //     if(dp[j][k] >=3){
    //       cout<<"YES"<<endl;
    //       f = 1;
    //       break;
    //     }
    //   }
    //   if(f)
    //     break;
    // }
    // if(!f)
    // cout<<"NO"<<endl;
    if(dp[0][n-1]>=3)
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;

  }
}
