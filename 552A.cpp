#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){

    int a[4];

    for(int i=0;i<4;i++)
        cin>>a[i];

    int largest=a[0], index=0;

    for(int i=1;i<4;i++){
        if(a[i]>largest){
            largest = a[i];
            index = i;
        }
    }

    for(int i=0;i<4;i++){
        if(index != i){
            cout<<largest-a[i]<<" ";
        }
    }
    cout<<endl;
}
