#include<bits/stdc++.h>

using namespace std;

int n,k;
int ara[6000];
map<int, vector<int> > colorMap;

void printColor(){

    for(int i=0;i<n;i++){
        colorMap[ara[i]].push_back(i);
    }

    //find out if it's impossible to color the array
    for(map<int, vector<int> >::iterator it = colorMap.begin();it!=colorMap.end(); it++){

        if(it->second.size() > k){
            cout<<"NO"<<endl;
            return;
        }
    }

    int c = 1;
    for(map<int, vector<int> >::iterator it = colorMap.begin();it!=colorMap.end(); it++){

        for(int i=0;i<it->second.size();i++){
            ara[it->second[i]] = c;

            if(c == k)
                c = 1;
            else
                c++;
        }

    }

    cout<<"YES"<<endl;

    for(int i=0;i<n;i++){
        cout<<ara[i]<<" ";
    }
    cout<<endl;
}

int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){

        cin>>ara[i];
    }

    printColor();

}
