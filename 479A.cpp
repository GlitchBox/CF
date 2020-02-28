#include<bits/stdc++.h>

using namespace std;

int main(){

    int n,k;
    cin>>n>>k;

    while(k>0){
        int remainder = n%10;

        if(remainder<k){
            n = (n-remainder)/10;
            k = k - remainder -1;
        }
        else{
            n = n - k;
            k = 0;
        }

    }
    cout<<n<<endl;

}
