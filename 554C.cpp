#include<bits/stdc++.h>
#include <numeric>
#define ll long long
#define inf 1000000009
using namespace std;

int main(){

    int a,b;
    cin>>a>>b;
    ll smallest = -1;
    ll ret = -1;

    if(a==b){
        cout<<0<<endl;
        return 0;
    }

    ll limit = min(__gcd(a,b), 100000000);
    smallest = std::lcm(a,b);
    for(ll i=1;i<limit;i++){

        ll temp = std::lcm(a+i,b+i);
        if(temp<smallest){
            smallest = temp;
            ret = i;
        }
    }

    cout<<ret<<endl;
}
