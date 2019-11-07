#include<bits/stdc++.h>
#define maxSize 100010
using namespace std;

int n,m;
int cats[maxSize];
int visited[maxSize];
vector<int>graph[maxSize];

int dfs(int node, int catsEncountered);

int main(){

    int a,b;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>cats[i];

    for(int i=0;i<n-1;i++){
        cin>>a>>b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    /*for(int i=1;i<=n;i++)
        cout<<visited[i]<<" ";
    cout<<endl;*/

    /*for(int i=1;i<=n;i++){
        cout<<i<<": ";
        for(int j=0;j<graph[i].size();j++)
            cout<<graph[i][j]<<" ";
        cout<<endl;
    }*/
    cout<<dfs(1,0)<<endl;

}

int dfs(int node, int catsEncountered){


    //cout<<"node: "<<node<<" cats: "<<catsEncountered<<endl;
    //cout<<graph[node].size()<<endl;
    visited[node] = 1;

    if(catsEncountered>m)
        return 0;

    if(graph[node].size()<2 && ((node != 1 && n>1)||(n == 1)) ){
            if(catsEncountered + cats[node]<=m)
                return 1;
            else
                return 0;
    }

    int ret = 0;
    //catsEncountered += cats[node];
    for(int i=0;i<graph[node].size();i++){

        if(!visited[graph[node][i]] && !cats[node])
            ret += dfs(graph[node][i],0);
        else if(!visited[graph[node][i]] && cats[node] && (cats[node] + catsEncountered<=m))
            ret += dfs(graph[node][i],catsEncountered+cats[node]);
    }

    //cout<<"node: "<<node<<" ret: "<<ret<<endl;
    return ret;

}
