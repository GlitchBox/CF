#include<bits/stdc++.h>
#define ll long long
#define maxSize 1000000

using namespace std;

int ara[maxSize];
void splitter(int n);

int main(){

    int n;
    cin>>n;

    for(int i=0;i<n;i++){

        cin>>ara[i];
    }

    sort(ara,ara+n);

    splitter(n);
}

void splitter(int n){

    priority_queue<int> dec;
    priority_queue<int, vector<int>, greater<int> > incQ;

    for(int i=0;i<n;){

        if(i+1<n && ara[i+1]==ara[i]){
            incQ.push(ara[i]);
            dec.push(ara[i+1]);

            if(i+2<n && ara[i+2] == ara[i]){
                cout<<"NO"<<endl;
                return;
            }

            i += 2;
        }
        else{
            incQ.push(ara[i]);
            i++;
        }


    }

    cout<<"YES"<<endl;
    cout<<incQ.size()<<endl;
    while(!incQ.empty()){
        cout<<incQ.top()<<" ";
        incQ.pop();
    }
    cout<<endl;

    cout<<dec.size()<<endl;
    while(!dec.empty()){
        cout<<dec.top()<<" ";
        dec.pop();
    }
    cout<<endl;
}
