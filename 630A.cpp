#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int T, l,r,d,u,x,y,x1,y1,x2,y2;
  cin>>T;

  while(T>0){
    cin>>l>>r>>d>>u;
    cin>>x>>y>>x1>>y1>>x2>>y2;
    if(x1==x2 && (l!=0 || r!= 0)){
      cout<<"NO"<<endl;
      T--;
      continue;
    }
    else if(y1==y2 && (d!=0 || u!= 0)){
      cout<<"NO"<<endl;
      T--;
      continue;
    }


      int newX = x - l + r;
      int newY = y -d +u;

      if(x1<=newX && newX<=x2 && y1<=newY && newY<=y2)
        cout<<"YES"<<endl;
      else
        cout<<"NO"<<endl;

    T--;
  }
}
