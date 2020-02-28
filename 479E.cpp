#include<bits/stdc++.h>
#define ll long LONG_LONG_MAX
#define maxSize 1000000
using namespace std;

vector<int> graph[maxSize];
int visited[maxSize];
int n, m;

int isCycle(int startNode, int parentNode, int currentNode){

    //printf("%d %d\n", startNode, currentNode);

    if(graph[currentNode].size() != 2){
        visited[currentNode] = 1;
        return 0;
    }

    if(currentNode == startNode && visited[startNode]){
        visited[currentNode] = 1;
        return 1;
    }

    int neighborNode = -1;
    for(int i=0;i<graph[currentNode].size();i++){

        if((!visited[graph[currentNode][i]]) || (graph[currentNode][i] == startNode && parentNode != startNode))
            neighborNode = graph[currentNode][i];
    }

    visited[currentNode] = 1;

    if(neighborNode ==-1)
        return 0;

    return isCycle(startNode, currentNode,neighborNode);
}

int main(){

    cin>>n>>m;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int totalCycles = 0;

    for(int i=1;i<=n;i++){
        if(!visited[i])
            totalCycles += isCycle(i,-1 ,i);
    }

    cout<<totalCycles<<endl;
}
