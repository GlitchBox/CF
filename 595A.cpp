#include<bits/stdc++.h>
#define ll long LONG_LONG_MAX

using namespace std;

vector<int> teams;
int numbers[1000];

int main(){

    int n,q;

    cin>>q;

    for(int i=0;i<q;i++){
        cin>>n;

        for(int j=0;j<n;j++){
            cin>>numbers[j];
        }

        sort(numbers, numbers+n);

        teams.push_back(numbers[0]);

        for(int j=1;j<n;j++){

            bool isInserted = false;
            for(int k=0;k<teams.size();k++){
                int diff = numbers[j] - teams[k];

                if(diff>1){
                    teams[k] = numbers[j];
                    isInserted = true;
                    break;
                }
            }

            if(!isInserted)
                teams.push_back(numbers[j]);
        }

        cout<<teams.size()<<endl;
        teams.clear();
    }
}
