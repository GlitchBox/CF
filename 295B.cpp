#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>

using namespace std;

int leastCost(int n, int target);

int main(){

    int n,m;
    cin>>n>>m;

    if(n>=m){
        cout<<n-m<<endl;
    }
    else{
        cout<<leastCost(n,m);
    }
}

int leastCost(int n, int target){

    int steps = 0;

    while(target>n){
        if(target%2)
            target++;
        else
            target /= 2;
        steps++;
    }

    return steps + n - target;

}
