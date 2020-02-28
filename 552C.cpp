#include<bits/stdc++.h>
#define ll long long
#define FF 3
#define RS 2
#define CS 2
using namespace std;

string ss[7] = {"cs","rs","ff","ff","rs","cs","ff"};

int main(){

    int ff,rs,cs, ret =0;
    cin>>ff>>rs>>cs;

    if(ff>=FF && rs>=RS && cs>=CS){
        int smallest = ff;

        if(smallest>rs)
            smallest = rs;
        if(smallest>cs)
            smallest = cs;

        if(smallest == ff)
            ret = (smallest/FF)*7;
        else if(smallest == rs)
            ret = (smallest/RS)*7;
        else
            ret = (smallest/CS)*7;

       ff -= ret; rs -= ret; cs -= ret;
    }

    int mostDays = -1;
    for(int i=0;i<7;i++){

        int days = 0;

        for(int j=0;j<7;j++){

            int ind = (i+j)%7;

            if(ss[ind] == "ff"){

                if(ff>0){
                    ff--;
                    days++;
                }
                else
                    break;
            }
            else if(ss[ind] == "rs"){

                if(rs>0){
                    rs--;
                    days++;
                }
                else
                    break;
            }
            else if(ss[ind]=="cs"){
                if(cs>0){
                    cs--;
                    days++;
                }
                else
                    break;

            }
        }

        if(mostDays==-1)
            mostDays = days;
        else if(mostDays<days)
            mostDays = days;



    }

    cout<<ret+mostDays<<endl;

}
