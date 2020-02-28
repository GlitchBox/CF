#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000

using namespace std;

int n,s;
string dp[120][910];
string numbers[10] = {"0","1","2","3","4","5","6","7","8","9"};

string leastNumber(int digits, int sum);
string largestNumber(int digits, int sum);
void setDP();
bool isPossible(int digits, int sum);

int main(){


    cin>>n>>s;

    if(n==1 && s==0)
        cout<<"0 0"<<endl;
    else{
        setDP();
        cout<<leastNumber(0,s)<<" ";

        setDP();
        cout<<largestNumber(0,s)<<endl;
    }

}

void setDP(){

    for(int i=0;i<=n;i++){
        for(int j=0;j<=s;j++)
            dp[i][j] = "-1";
    }
}

string leastNumber(int digits, int sum){

   // cout<<"digits: "<<digits<<" sum: "<<sum<<endl;

    if(dp[digits][sum] != "-1"){
        return dp[digits][sum];
    }

    if(digits == n && sum == 0)
        return "";

    if(digits == n && sum)
        return dp[digits][sum] = "-1";

    string ret = "-1";

    int limit = min(sum,9);
    int i;
    if(digits == 0)
        i = 1;
    else
        i = 0;

    while(i<=limit && ret == "-1"){
        if(isPossible(n-digits-1, sum - i)){
            string temp = leastNumber(digits+1, sum-i);
            if(temp != "-1")
                ret = numbers[i] + temp;
        }
        i++;
    }

    return dp[digits][sum] = ret;


}

string largestNumber(int digits, int sum){

    if(dp[digits][sum] != "-1"){
        return dp[digits][sum];
    }

    if(digits == n && sum == 0)
        return "";

    if(digits == n && sum)
        return dp[digits][sum] = "-1";

    string ret = "-1";

    int i=min(9,sum);
    int limit;
    if(!digits)
        limit = 1;
    else
        limit = 0;

    while(i>=limit && ret == "-1"){
        if(isPossible(n-digits-1, sum - i)){
            string temp = largestNumber(digits+1, sum-i);
            if(temp != "-1")
                ret = numbers[i] + temp;
        }
        i--;
    }

    return dp[digits][sum] = ret;


}

bool isPossible(int digits, int sum){

    return (sum>=0 && sum<= digits*9);
}
