#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    string s;
    cin>>n;
    cin>>s;

    int maxNumber = -1, startIndex = 0;

    for(int i=0;i<n-1;i++){
        string subString = s.substr(i,2);
        int tempNumber = 1;

        for(int j = i+1; j<n;j++){
            if(j+1<n){
                string temp = s.substr(j,2);

                if(temp==subString)
                    tempNumber++;
            }

        }

        if(tempNumber>maxNumber){
            maxNumber = tempNumber;
            startIndex = i;
        }
    }

    cout<<s.substr(startIndex,2)<<endl;
}
