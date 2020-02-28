#include<bits/stdc++.h>
#define ll long long
#define maxSize 100010
#define pii pair<ll, ll>
using namespace std;

int ara[maxSize];
ll dp[maxSize];
vector<pii> numbers;
void fillVector(int n);
ll mostGain(int n);

int main(){
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>ara[i];
    }

    sort(ara,ara+n);
    fillVector(n);

    /*for(int i=0;i<numbers.size();i++)
        cout<<numbers[i].first<<" "<<numbers[i].second<<endl;*/

    cout<<mostGain(n)<<endl;

}

void fillVector(int n){
    int i=0;

    while(i<n){

        int j = i+1;
        int numberCount = 1;
        while(j<n && ara[i] == ara[j]){
            numberCount++;
            j++;
        }
        numbers.push_back(make_pair(ara[i],numberCount));

        i = j;
    }
}

ll mostGain(int n){


    for(int i=0;i<numbers.size();i++){
        dp[i] = numbers[i].first * numbers[i].second;

        if(i>0){
            if(numbers[i-1].first+1 == numbers[i].first){
                if(i>1)
                    dp[i] += dp[i-2];
            }
            else
                dp[i] += dp[i-1];
        }

        if(i>0)
            dp[i] = max(dp[i-1],dp[i]);
    }

    return dp[numbers.size()-1];

}
