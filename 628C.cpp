#include<bits/stdc++.h>
#define maxSize 100010
using namespace std;

vector<int>graph[maxSize];
int visited[maxSize];
typedef struct edges{
  int u;
  int v;
  //int val;
}edges;

int edgeVals[maxSize];
// unordered_map<edges, int> edgeVals;

int main(){
  int n,u,v;
  cin>>n;

  //construct the graph
  int currentVal = 0;
  for(int i=0;i<n-1;i++){
    cin>>u>>v;
    graph[u].push_back(v);
    graph[v].push_back(u);
    edgeVals[i] = currentVal;
    currentVal++;
    // edges s = edges{u,v};
    // edgeVals[e] = -1;
  }

  for(int i=0;i<n-1;i++)
    cout<<edgeVals[i]<<endl;
  // while(1);
  // // for(int i=0;i<n-1;i++)
  // //   cout<<edgeVals[i].u<<" "<<edgeVals[i].v<<endl;
  // for (auto x : edgeVals)
  //     cout << x.first.u << " " << x.first.v<<" "<<x.second<<endl;
  //
  // while(1);
  //
  // int rootNode = 1;
  // queue<int> q;
  // q.push(rootNode);
  // visited[rootNode] = 1;
  // int currentVal = 0;
  //
  // while(!q.empty()){
  //   int currentNode = q.front();
  //
  //
  // }


}
