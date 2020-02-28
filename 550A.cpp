#include<bits/stdc++.h>
#define chars 26
using namespace std;

int charsInString[chars];

void ifDiverse(string s);

int main(){

    int n;string s;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>s;
        memset(charsInString, 0, 26*sizeof(int));
        ifDiverse(s);
    }

}

void ifDiverse(string s){


    for(int i=0;i<s.length();i++){

        //two things might happen

        //this character has appeared before
        if( charsInString[s[i]-'a'])
        {
            cout<<"No"<<endl;
            return;
        }

        else
            charsInString[s[i]-'a']++;
    }

    /*for(int i=0;i<chars;i++)
        cout<<charsInString[i]<<endl;
    while(1);*/

    //now I'll check if the characters are consecutive
    int i=0;
    while(!charsInString[i]){
        i++;
    }

    //now i denotes the first index in charsInString which contains 1
    int len = 0;

    while(i<chars && charsInString[i]){
        len++;
        i++;
    }

    if(len<s.length()){
        cout<<"No"<<endl;
        return;
    }


    cout<<"Yes"<<endl;
}
