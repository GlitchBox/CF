#include<bits/stdc++.h>

using namespace std;

int skill[200010];

int main(){
  int T,n;
  cin>>T;

  while(T){

    cin>>n;
    for(int i=0;i<n;i++){
      cin>>skill[i];
    }

    unordered_map<int, int> same;
    set<int> unique;

    for(int i=0;i<n;i++){
      unique.insert(skill[i]);
      unordered_map<int, int>::iterator it = same.find(skill[i]);
      if(it == same.end())
        same[skill[i]] = 0;
      same[skill[i]] += 1;
    }
    int sameLargest = 0;
    int uniqueNo = unique.size();

    for(unordered_map<int, int>::iterator it2 = same.begin(); it2 != same.end(); it2++){
      if(it2->second > sameLargest)
        sameLargest = it2->second;
    }

    if(sameLargest==uniqueNo)
      cout<<uniqueNo-1<<endl;
    else
      cout<<min(sameLargest, uniqueNo)<<endl;

    T--;
  }
}
