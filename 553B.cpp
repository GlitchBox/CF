#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define inf 1000000000
#define maxSize 510
using namespace std;

int ara[maxSize][maxSize];

void findPath(int n, int m);

int main(){

    int n, m;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
        cin>>ara[i][j];
    }

    findPath(n,m);

}

void findPath(int n, int m){

    //look for a row which has different elements in it
    int ifDiffi = -1, ifDiffj = -1;
    for(int i=0;i<n;i++){
        for(int j=1;j<m;j++){
            if(ara[i][0] != ara[i][j]){
                ifDiffi = i;
                break;
            }
        }
    }

    //we have found a row which has different elements in it
    if(ifDiffi != -1){
        int ret = 0;

        for(int i = 0;i<n; i++){
            if(ifDiffi != i){
                ret ^= ara[i][0];
            }
        }


        for(int j=0;j<m;j++){
            int temp = ret;
            temp ^= ara[ifDiffi][j];

            if(temp){
                ifDiffj = j;
                break;
            }

        }
        if(ifDiffj != -1){
            cout<<"TAK"<<endl;
            for(int i=0;i<n;i++){
                if(i == ifDiffi)
                    cout<<ifDiffj+1<<" ";
                else
                    cout<<"1 ";
            }
            cout<<endl;
        }
        else
            cout<<"NIE"<<endl;
    }

    //either every element of the array is same
    //or every element on each row is the same and two rows can be different
    else{
        int ret = 0;
        for(int i=0;i<n;i++){
            ret ^= ara[i][0];
        }

        if(ret){
            cout<<"TAK"<<endl;

            for(int i=0;i<n;i++)
                cout<<"1 ";
            cout<<endl;
        }
        else
            cout<<"NIE"<<endl;
    }
}
