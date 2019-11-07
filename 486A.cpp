#include<bits/stdc++.h>
#define ll long long
#define maxSize 200
#define pii pair<int,int>

using namespace std;

vector<pii> numbers;
vector<int> distinctNumbers;

int main(){

    int n,k,a;

    cin>>n>>k;

    for(int i=0;i<n;i++){
        cin>>a;
        numbers.push_back(make_pair(a,i));
    }

    sort(numbers.begin(), numbers.end());

    /*for(int i=0;i<n;i++)
        cout<<numbers[i].first<<" "<<numbers[i].second<<endl;
    cout<<endl;*/

    int index = 1, currentNumber=numbers[0].first;
    distinctNumbers.push_back(numbers[0].second);

    while(index<n){
        if(numbers[index].first != currentNumber){
            currentNumber = numbers[index].first;
            distinctNumbers.push_back(numbers[index].second);
        }
        index++;
    }

    if(distinctNumbers.size()<k)
        cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        for(int i=0;i<k;i++){
            cout<<distinctNumbers[i]+1<<" ";
        }
        cout<<endl;
    }


}
