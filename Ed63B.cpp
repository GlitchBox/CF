#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;

    string s;
    cin>>s;

    int moves = n-11;
    int opponentMove = moves/2;

    int num8 = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='8')
            num8++;
    }

    if(num8>opponentMove){
        //cout<<"YES"<<endl;

        //look for the position of k+1th 8
        int pos = 0, cnt = 0;
        while(cnt<=opponentMove){
            if(s[pos]=='8')
                cnt++;
            pos++;
        }

        if(pos-1<=moves)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    else
        cout<<"NO"<<endl;

}
