#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k,l,c,d,p,nl,np;

    cin>>n>>k>>l>>c>>d>>p>>nl>>np;

    int poss1 = (k*l)/(nl*n);
    int poss2 =  (c*d)/(n);
    int poss3 = (p)/(n*np);

    cout<<min(min(poss1,poss2),poss3)<<endl;
}
