#include<bits/stdc++.h>

using namespace std;

int n,x,y;
int doors[200];

int main(){


    cin>>n>>x>>y;

    for(int i=0;i<n;i++){
        cin>>doors[i];
    }

    int lessStrong = 0;
    for(int i=0;i<n;i++){

        if(doors[i]<=x)
            lessStrong++;
    }

    if(x<=y){
        if(lessStrong%2){
            cout<<(lessStrong/2)+1<<endl;
            return 0;
        }
        else{
            cout<<lessStrong/2<<endl;
            return 0;
        }

    }

    else{
        cout<<n<<endl;
        return 0;
    }
}
