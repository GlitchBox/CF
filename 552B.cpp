#include<bits/stdc++.h>
#define ll long long

using namespace std;

int ara[110];

int leastVal(int n);

int main(){

    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>ara[i];
    }

    cout<<leastVal(n);
}

int leastVal(int n){

    int ret = -1;

    int largest = ara[0], smallest = ara[0];
    for(int i=1;i<n;i++){

        if(ara[i]>largest)
            largest = ara[i];
        else if(ara[i]<smallest)
            smallest = ara[i];
    }

    int limit = (smallest + largest)/2;


    /*int ifPres = 0;

    for(int i=0;i<n;i++){
        if(limit == ara[i]){
            ifPres = 1;
            break;
        }
    }

    if(!ifPres){

         int ifOtherVal = 0;

        for(int i=0;i<n;i++){
            if(smallest<ara[i] && ara[i]<largest){
                    ifOtherVal = 1;
                    break;
            }
        }

        if(ifOtherVal){
            return -1;
        }
        else{
            if((largest+smallest)%2 == 0)
                return limit - smallest;

            return largest - smallest;
        }
    }
    else{
        ret = abs(limit - smallest);
    }*/
    while(limit>=0){

        int ifFound = 1;
        int diff = -1;

        for(int i=0;i<n;i++){
            if(limit!=ara[i]){
                if(diff == -1)
                    diff = abs(limit - ara[i]);
                else if(diff != abs(limit - ara[i])){
                        ifFound = 0;
                        break;
                }
            }
        }
        if(ifFound){

            if(limit == smallest)
                return largest - limit;
            else if(limit == largest)
                return limit - smallest;

            return diff;
        }


        limit--;
    }

    return ret;

}
