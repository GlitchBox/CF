#include<bits/stdc++.h>
#define inf 999999
using namespace std;

int puzzles[60],n,m;

int findDiff();

int main(){

    cin>>n>>m;

    for(int i=0;i<m;i++){
        cin>>puzzles[i];
    }

    cout<<findDiff()<<endl;
}

int findDiff(){

    int ret = inf;

    for(int i=0;i<m;i++){
        int smallest = puzzles[i],largest = puzzles[i], diff = -1;
        int taken[60];
        memset(taken, 0, sizeof(taken));
        taken[i] = 1;

        for(int j=1;j<n;j++){
            int tempDiff = inf, tempInd;

            for(int k=0;k<m;k++){
                if(!taken[k]){
                    int temp2 = abs(smallest - puzzles[k]);
                    if(temp2<tempDiff){
                        tempDiff  = temp2;
                        tempInd = k;
                    }
                }
            }

            taken[tempInd] = 1;
            if(puzzles[tempInd] < smallest){
                smallest = puzzles[tempInd];
                tempDiff = largest - smallest;

            }

            if(puzzles[tempInd] > largest)
                largest = puzzles[tempInd];

            if(diff<tempDiff)
                diff = tempDiff;
        }

        if(ret>diff)
            ret = diff;

    }

    return ret;
}
