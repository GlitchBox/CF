#include<bits/stdc++.h>

using namespace std;

int numbers[3];

int maxNumbers();

int main(){
    int t,n,a;
    cin>>t;

    for(int i=0;i<t;i++){
        cin>>n;
        for(int j=0;j<3;j++)
            numbers[j] = 0;
        for(int j=0;j<n;j++){
            cin>>a;
            numbers[a%3]++;
        }

        cout<<maxNumbers()<<endl;
    }
}

int maxNumbers(){

    int ret = 0, common = numbers[1]<numbers[2]? numbers[1]:numbers[2];

    numbers[1] -= common;
    numbers[2] -= common;

    ret = numbers[0] + (numbers[1]/3) + (numbers[2]/3) + common;

    return ret;



}
