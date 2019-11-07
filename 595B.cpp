#include<bits/stdc++.h>
#define ll long LONG_LONG_MAX

using namespace std;

int permutation[1000000];
int books[300];
int days[300];
int visited[300];

int requiredDays(int realIndex, int currentIndex){

    if(realIndex == currentIndex)
        return 0;

    if(currentIndex == -1)
        return 1 + requiredDays(realIndex, permutation[realIndex]-1);

    return 1 + requiredDays(realIndex, permutation[currentIndex]-1);
}

int main(){

    int n,q;

    cin>>q;

    for(int i=0;i<q;i++){
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>permutation[j];
            books[j] = j;
            days[j] = 0;
            visited[j] = -1;
        }

        int returned = 0;
        /*while(returned<n){

            for(int j=0;j<n;j++){

            }
        }*/

        for(int j=0;j<n;j++){
            cout<<requiredDays(j, -1)<<" ";
        }
        cout<<endl;
    }

}

