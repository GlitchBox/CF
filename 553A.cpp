#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define inf 1000000000
#define maxSize 3010
using namespace std;

int dist(char c, char x);

int main(){

    int ret = inf;
    int n;
    cin>>n;

    string s;
    cin>>s;

    for(int i=0;i<n-3;i++){
        int tempCost = 0;
        tempCost += dist('A',s[i]);
        tempCost += dist('C',s[i+1]);
        tempCost += dist('T',s[i+2]);
        tempCost += dist('G', s[i+3]);

        if(tempCost<ret)
            ret = tempCost;

    }

    cout<<ret<<endl;

}

int dist(char target, char x){

    char largest, smallest;

    if(target == x)
        return 0;

    if(target<x){
        largest = x;
        smallest = target;
    }
    else{
        largest = target;
        smallest = x;
    }

    int ret1 = largest - smallest;
    int ret2 = smallest + 26 - largest;

    if(ret1<ret2)
        return ret1;

    return ret2;


}
