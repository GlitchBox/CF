#include<bits/stdc++.h>
#define ll long long
#define maxSize 1000000

using namespace std;

int I[maxSize], sequence[maxSize];
int n, numbers[maxSize];

//return the lowerbound index of the number "num" in the array I
/*int lowerBound(int num){

    int lo = 0;
    int hi = n-1;

    while(lo<=hi){
        int mid = (lo+hi)/2;

        if(num>I[mid])
            lo = mid + 1;
        else
            hi = mid - 1;

    }

    return lo;
}

int LIS(){

    I[0] = -1;

    for(int i=1;i<=n;i++){
        int loBound = lowerBound(numbers[i]);
    }
}*/

map<int,int> dp;
queue<int> lis;

void printLIS(){
    if(lis.empty()){
        return;
    }

    int ret = lis.front();
    lis.pop();

    printLIS();
    cout<<ret<<" ";

}

int main(){

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>numbers[i];
    }

    int lastNumber = -1, len = -1;
    for(int i=0;i<n;i++){

        if(dp.find(numbers[i]-1) == dp.end())
            dp[numbers[i]] = 1;
        else{
            dp[numbers[i]] = dp[numbers[i]-1] + 1;
        }

        if(dp[numbers[i]]>len){
            lastNumber = numbers[i];
            len = dp[numbers[i]];
        }
    }
    //cout<<len<<endl;
    //cout<<lastNumber<<endl;

    for(int j=n-1;j>-1;j--){
        if(numbers[j] == lastNumber){
            lis.push(j+1);
            lastNumber--;
        }
    }

    //cout<<lastNumber<<endl;
    //for(map<int, int>::iterator it = dp.begin(); it != dp.end(); it++)
    //    cout<<it->first<<" "<<it->second<<endl;

    cout<<len<<endl;
    printLIS();
    cout<<endl;


}


