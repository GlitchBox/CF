#include<bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin>>n;

    string s;
    cin>>s;

    for(int i=0;i<s.length()-1;i++){
        if(s[i]>s[i+1]){
            cout<<"YES\n"<<i+1<<" "<<i+2<<endl;
            return 0;
        }
    }

    cout<<"NO"<<endl;
}
