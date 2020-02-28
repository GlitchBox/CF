#include<bits/stdc++.h>
#define ll long long
using namespace std;

int leastSteps(ll n);

int main(){

    ll n;int q;

    cin>>q;
    for(int i=0;i<q;i++){

        cin>>n;
        cout<<leastSteps(n)<<endl;
    }

}

int leastSteps(ll n){

    int ret = 0;

    if(!n)
        return 0;

    while(n>1){



        if(!(n%2)){
            n /= 2;
            ret++;
        }
        else if(!(n%3)){
            n = (n*2)/3;
            ret++;
        }
        else if(!(n%5)){
            n = (n*4)/5;
            ret++;
        }
        else
            return -1;

        //cout<<n<<endl;
    }

    return ret;
}
