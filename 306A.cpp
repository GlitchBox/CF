#include<bits/stdc++.h>
#define AB 0
#define BA 1
#define none -1
#define both 2
using namespace std;

int main(){
    string s;
    cin>>s;

    int lastIndex1 = -1, lastIndex2 = -1;
    int state1 = none;
    int state2 = none;
    int state = none;


    for(int i=0;i<s.length()-1;i++){
        if(state1==none && s[i]=='A' && s[i+1]=='B'){
            state1 = AB;
            lastIndex1 = i+1;
        }
        else if(state1 == AB && s[i]=='B' && s[i+1]=='A'){
            if(lastIndex1 != i){
                state = both;
                break;
            }
        }

        if(state2==none && s[i]=='B' && s[i+1]=='A'){
            state2 = BA;
            lastIndex2 = i+1;
        }
        else if(state2==BA && s[i]=='A' && s[i+1]=='B'){
            if(lastIndex2 != i){
                state=both;
                break;
            }
        }
    }

    if(state==none)
        cout<<"NO\n";
    else
        cout<<"YES\n";
}
