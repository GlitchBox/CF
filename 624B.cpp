#include<bits/stdc++.h>

using namespace std;

typedef struct position{
  int oldPos;
  int val;
}position;

int alreadyCovered[110][110];
int p[200];
position a[200];

bool comparePositions(position a, position b){

  return a.val<b.val;
}

int bisection(int key, int n){
  int b = 0;
  int e = n-1;

  while(b<=e){
    int mid = (b+e)/2;

    if(p[mid]==key)
      return 1;
    else if(p[mid]>key)
      e = mid - 1;
    else
      b = mid + 1;
  }

  return -1;
}

int main(){

  int t, m , n, temp;
  cin>>t;

  for(int i=0;i<t;i++){
      cin>>m>>n;

      for(int j=0;j<m;j++){
        cin>>temp;
        a[j] = {j+1, temp};
      }
      for(int j=0;j<n;j++)
        cin>>p[j];

      for(int j=0;j<n;j++){
        for(int k=0;k<n;k++)
          alreadyCovered[j][k] = 0;
      }

      sort(a, a+m, comparePositions);
      // cout<<endl;
      // for(int j=0;j<m;j++)
      //   cout<<a[j].val<<" "<<a[j].oldPos<<endl;
      sort(p, p+n);

      //now for every element in the a array, I will check whether its "move area" is covered within the p array
      int f = 0;
      for(int j=0;j<m;j++){
        int b,e;
        if(a[j].oldPos>j+1){
            b = j+1;
            e = a[j].oldPos;
        }
        else{
          b = a[j].oldPos;
          e = j+1;
        }
        //cout<<b<<" "<<e<<endl;


        int key;
        for(key=b;key<e;key++){
          int ret = bisection(key, n);
          //cout<<"key: "<<key<<"ret: "<<ret<<endl;
          if(ret==-1){
              break;
          }
        }

        if(key<e){
            cout<<"NO"<<endl;
            f = 1;
            break;
        }


      }
      if(!f)
        cout<<"YES"<<endl;



  }


}
