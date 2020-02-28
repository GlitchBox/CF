#include<bits/stdc++.h>

using namespace std;

int divisors[150];
int ifDiv[150];
vector<int> divs;

int main(){

    memset(ifDiv,0,sizeof(ifDiv));

    int n;
    cin>>n;

    for(int i=0;i<n;i++){

        cin>>divisors[i];
    }

    int largest = -1;
    for(int i=0;i<n;i++){

        if(largest<divisors[i])
            largest = divisors[i];
    }

    for(int i=0;i<n;i++){

        if((largest%divisors[i]) == 0){
            int f = 0;

            for(int j=0;j<divs.size();j++){
                if(divisors[i] == divs[j]){
                    f = 1;
                    break;
                }
            }

            if(!f){
                divs.push_back(divisors[i]);
                ifDiv[i] = 1;
            }
        }
    }

    int largest2 = -1;
    for(int i = 0;i<n;i++){
        if(ifDiv[i] == 0 && divisors[i]>largest2)
            largest2 = divisors[i];
    }

    cout<<largest<<" "<<largest2<<endl;

}
