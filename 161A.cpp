#include<bits/stdc++.h>

using namespace std;

int main(){

    int element;
    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++){
            cin>>element;

            if(element){
                cout<< abs(i-3) + abs(j-3);
                return 0;
            }
        }
    }
}
