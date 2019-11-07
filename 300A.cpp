#include<bits/stdc++.h>
#define maxLength 6
using namespace std;

vector<int> quasiBinaries[maxLength];

void createQuasi();

int main(){

}

void createQuasi(){

    int firstNumbers = 1;
    //set the least number for every length
    for(int i=1;i<=maxLength;i++){
        quasiBinaries[i].push_back(firstNumbers);
        firstNumbers *= 10;
    }

    for(int i=2;i<=maxLength;i++){
        for(int j=1;j<i;i++){

        }
    }

}
