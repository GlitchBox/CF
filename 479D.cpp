#include<bits/stdc++.h>
#define ll long long

using namespace std;

int n;
ll numbers[150];
vector<ll> orderedNumber;
map<ll,int> visited;

void createVisited(){
    for(int i=0;i<n;i++)
        visited[numbers[i]] = 0;
}

int order(ll startIndex, int position){
    if(visited.find(startIndex) == visited.end())
        return 0;

    if(position==n-1){
        visited[startIndex] = 1;
        orderedNumber.push_back(startIndex);
        return 1;
    }

    int isValidBranch;
    if(!(startIndex%3))
        isValidBranch = order(startIndex/3, position+1) || order(startIndex*2, position+1);
    else
        isValidBranch = order(startIndex*2, position+1);

    if(isValidBranch==1){
        visited[startIndex] = 1;
        orderedNumber.push_back(startIndex);
        return 1;
    }

    return 0;




}



int main(){
    cin>>n;

    for(int i=0;i<n;i++)
        cin>>numbers[i];

    for(int i=0;i<n;i++){
        createVisited();
        int isFound = order(numbers[i],0);

        if(isFound ==1)
            break;

        orderedNumber.clear();
        visited.clear();

    }

    for(int i=n-1;i>-1;i--)
        cout<<orderedNumber[i]<<" ";

    cout<<endl;


}
