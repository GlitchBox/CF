#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define ipii pair<int, pii>
#define maxLen 1000000

using namespace std;

int k;

vector<int> numbers[maxLen];
vector<ipii> orderedLists;
vector<int> sums;

int main(){

    cin>>k;
    int n,a;

    for(int i=0;i<k;i++){
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>a;
            numbers[i].push_back(a);
        }
    }

    /*for(int i=0;i<k;i++){
        for(int j=0;j<numbers[i].size();j++)
            cout<<numbers[i][j]<<" ";
        cout<<endl;
    }*/
    for(int i=0;i<k;i++){
        sums.push_back(0);
        for(int j=0;j<numbers[i].size();j++){
            sums[i] += numbers[i][j];
        }
    }

    /*for(int i=0;i<sums.size();i++)
        cout<<sums[i]<<endl;*/

    for(int i=0;i<k;i++){
        for(int j=0;j<numbers[i].size();j++){
            orderedLists.push_back(make_pair(sums[i] - numbers[i][j],make_pair(i+1, j+1)));
        }
    }

    sort(orderedLists.begin(), orderedLists.end());

    /*cout<<endl;
    for(int i=0;i<orderedLists.size();i++)
        cout<<orderedLists[i].first<<" "<<orderedLists[i].second.first<<" "<<orderedLists[i].second.second<<endl;*/

    int currentSum = orderedLists[0].first;
    int currentSequence = orderedLists[0].second.first;
    int currentItem = orderedLists[0].second.second;
    int index = 1;

    while(index<orderedLists.size()){

        if(currentSum != orderedLists[index].first){
            currentSum = orderedLists[index].first;
            currentSequence = orderedLists[index].second.first;
            currentItem = orderedLists[index].second.second;
        }

        else if(currentSum == orderedLists[index].first && currentSequence != orderedLists[index].second.first){
            cout<<"YES"<<endl;
            cout<<currentSequence<<" "<<currentItem<<endl;
            cout<<orderedLists[index].second.first<<" "<<orderedLists[index].second.second<<endl;
            return 0;
        }

        index++;
    }

    cout<<"NO"<<endl;
}
