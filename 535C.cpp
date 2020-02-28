#include<bits/stdc++.h>
using namespace std;

int red[3],green[3], blue[3];
string garland;


int main(){

    int n;
    cin>>n;
    cin>>garland;

    string seq = "RGB";
    string finalSeq;
    sort(seq.begin(),seq.end());

    int diff = 10000007;
    do{
   // cout<<seq<<endl;
            int temp=0;
            for(int i=0;i<n;i++){

                if(garland[i] != seq[i%3])
                    temp++;
            }

            if(temp<diff){
                diff = temp;
                finalSeq = seq;
            }

    }while(next_permutation(seq.begin(), seq.end()));

    for(int i=0;i<n;i++)
        garland[i] = finalSeq[i%3];

    cout<<diff<<endl<<garland<<endl;

}
