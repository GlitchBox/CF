#include<bits/stdc++.h>
#define ll long long
#define maxSize 100010
#define inf 1000000000
#define pii pair<int,int>
using namespace std;

vector<int> graph[maxSize];
bool visited[maxSize];
priority_queue<pii, vector<pii>, greater<pii> > bribes;

void dfs(int src);
ll leastCost();

int main(){
    int n, m, u, v, x;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        cin>>x;
        bribes.push(make_pair(x,i+1));
    }
    for(int i=0;i<m;i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }



    cout<<leastCost()<<endl;

}


//an overview of how the algorithm works
//at first, I'll sort the array containing bribes for each character in increasing order
//when I pick the person who I can bribe with the least cost, two cases could occur

//1.that chosen person is a member of a strongly connected component, in that case by bribing that person
// I can spread the rumor amongst the connected component with least cost
//2. the chosen person is the only member in the connected component, in that case I get to spread the rumor to him
//O(V+E+n)

ll leastCost(){

    ll cost = 0;
    while(!bribes.empty()){
        pii top = bribes.top();
        bribes.pop();
        int charNo = top.second;
        int bribe = top.first;

        if(visited[charNo] == false){
            cost += bribe;
            dfs(charNo);
        }

    }
    return cost;

}

void dfs(int src){

    /*if(visited[src] == true)
        return;*/

    visited[src] = true;
    for(int i=0;i<graph[src].size();i++){
        if(visited[graph[src][i]] == false)
            dfs(graph[src][i]);
    }

    return;
}
