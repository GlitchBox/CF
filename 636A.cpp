#include<bits/stdc++.h>

using namespace std;

int main(){

  int T;
  cin>>T;

  while(T){
    int num;
    cin>>num;

    int power = 2;
    int mult = 1;
    int n;

    while(1){
      mult += power;

      if(num%mult==0){
        n = num/mult;
        break;
      }

      power *=2;

    }
    cout<<n<<endl;
    T--;
  }
}
