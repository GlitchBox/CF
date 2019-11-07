#include<bits/stdc++.h>
#define ll long long
#define maxSize 1000000

using namespace std;

int n,q;
int permutation[maxSize];
int days[maxSize];
map<int, int> visited;

int main(){

    cin>>q;

    for(int i=0;i<q;i++){
        cin>>n;

        for(int j=0;j<n;j++)
            cin>>permutation[j];

        for(int j=0;j<n;j++){
            if(visited.find(j) == visited.end()){

                int currentPerson = j, returnDay = 0;
                vector<int> currentLoop;

                while(visited.find(currentPerson) == visited.end()){
                    currentLoop.push_back(currentPerson);
                    visited[currentPerson] = 1;
                    returnDay++;
                    currentPerson = permutation[currentPerson] - 1;

                }

                for(int k=0;k<currentLoop.size();k++)
                    days[currentLoop[k]] = returnDay;
            }
        }

        for(int j=0;j<n;j++)
            cout<<days[j]<<" ";
        cout<<endl;
        visited.clear();
    }

}
