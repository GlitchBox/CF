#include<bits/stdc++.h>
#define ll long long
#define pis pair<int, string>

using namespace std;

int n;
vector<pis> strings;

bool checkIfEqual(string smaller, string larger, int indexIntoLarger){

    int len = smaller.length();

    for(int i=0;i<len;i++){
        if(smaller[i]!=larger[i+indexIntoLarger])
            return false;
    }

    return true;
}

bool stringOrdering(){

    for(int i=0;i<n-1;i++){
        int smallerStringLen = strings[i].first;
        int largerStringLen = strings[i+1].first;
        int diff = largerStringLen - smallerStringLen;

        //cout<<strings[i].second<<" "<<strings[i+1].second<<" "<<diff<<endl;

        bool isFound = false;
        for(int j=0;j<=diff;j++){
            if(checkIfEqual(strings[i].second, strings[i+1].second, j)){
                isFound = true;
                break;
            }
        }

        if(!isFound)
            return false;
    }

    return true;
}

int main(){
    cin>>n;

    for(int i=0;i<n;i++){
        string s;
        cin>>s;

        strings.push_back(make_pair(s.length(), s));
    }

    sort(strings.begin(), strings.end());

    /*cout<<endl;
    for(int i=0;i<strings.size();i++){
        cout<<strings[i].second<<endl;
    }*/
    //cout<<checkIfEqual("abb", "pabba",0)<<endl;

    if(stringOrdering()){
        cout<<"YES"<<endl;

        for(int i=0;i<n;i++)
            cout<<strings[i].second<<endl;
    }

    else
        cout<<"NO"<<endl;


}
