#include<bits/stdc++.h>
#define ll long long
#define maxSize 2010
using namespace std;

int ara[maxSize];

void initAra();

int main(){

    initAra();

    int n;
    cin>>n;

    ll ret = 0;
    for(int i=1;i<=n;i++)
        ret += ara[i];

    cout<<ret<<endl;

}

void initAra(){

    ara[1] = 1;

    for(int i=2;i<maxSize;i++){
        ara[i] = ara[i-1] + i-1;
    }
}
