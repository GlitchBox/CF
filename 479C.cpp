#include<bits/stdc++.h>
#define ll long long
#define maxLen 1000000
using namespace std;

int n,k;
queue<int> distinctNumbers;
map<int, int> ifPresent;
int numbers[maxLen];

int main(){

    cin>>n>>k;
    int a;

    for(int i=0;i<n;i++){
       cin>>numbers[i];
       ifPresent[numbers[i]]++;
    }


    map<int, int>::iterator itr;
    int prev = -1;

    for(itr = ifPresent.begin(); itr != ifPresent.end(); itr++){
        ifPresent[itr->first] += ifPresent[prev];
        prev = itr->first;
    }

    /*map<int, int>::iterator itr2;
    for (itr2 = ifPresent.begin(); itr2 != ifPresent.end(); itr2++) {
        cout << '\t' << itr2->first
             << '\t' << itr2->second << '\n';
    }*/

    if(k==0){
        if(ifPresent.find(1) == ifPresent.end()){
            cout<<1<<endl;
            return 0;
        }
        else{
            cout<<-1<<endl;
            return 0;
        }
    }

    int ret = -1;
    for(itr = ifPresent.begin(); itr != ifPresent.end(); itr++){
        if(itr->second == k){
            ret = itr->first;
            break;
        }
    }

    cout<<ret<<endl;

}
