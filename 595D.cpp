#include<bits/stdc++.h>
#define ll long long
#define maxNum 10000

using namespace std;

vector<int> numbers;
int q;

int main(){

    cin>>q;
    for(int i=0;i<q;i++){
        ll n;
        cin>>n;
        ll n2 = n;

        vector<int> trits;//digit equivalent in ternary number system
        while(n>0){
            trits.push_back(n%3);
            n /= 3;
        }

        int pos2 = -1;
        for(int j=0;j<trits.size();j++){

            if(trits[j] == 2)
                pos2 = j;
        }

        if(pos2==-1){
            cout<<n2<<endl;
        }

        else{
            int pos0 = -1;
            for(int k=pos2+1; k<trits.size(); k++){
                if(trits[k]==0){
                    pos0 = k;
                    trits[pos0] = 1;
                    break;
                }
            }

            if(pos0==-1){

                int p = trits.size();

                ll ret = 1;
                for(int k=0;k<p;k++)
                    ret *= 3;

                cout<<ret<<endl;
            }

            else{

                ll p = 1;
                ll ret =0;
                for(int k=0;k<pos0;k++){
                    p *= 3;
                }

                for(int k=pos0;k<trits.size();k++){
                    ret += (p*trits[k]);
                    p *= 3;
                }

                cout<<ret<<endl;

            }

        }

    }

}
