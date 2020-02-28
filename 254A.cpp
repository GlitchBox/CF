#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

int n,m;
int fx[4] = {-1,1,0,0};
int fy[4] = {0,0,-1,1};
char board[110][110];

void bfs();

int main(){

    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
        }
    }

    bfs();

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout<<board[i][j];
        cout<<endl;
    }
}

void bfs()
{
    int goodPlaces;
    while(1){

        //find out how many good places are left to find
        goodPlaces=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='.')
                    goodPlaces++;
            }
        }

        //cout<<"Good places: "<<goodPlaces<<endl;
        if(!goodPlaces)
            return;

        //find the first node that can be filled with a chess piece
        pii source;
        int f = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == '.'){
                    source = make_pair(i,j);
                    f = 1;
                    break;
                }
                if(f)
                    break;
            }

        }
        //place A white piece in that position
        board[source.first][source.second] = 'W';
       // cout<<"source: "<<source.first<<" "<<source.second<<endl;

        queue<pii>q; //A queue containing STL pairs
        q.push(source);
        while(!q.empty())
        {
            pii top=q.front(); q.pop();
            for(int k=0;k<4;k++)
            {
                int tx=top.first+fx[k];
                int ty=top.second+fy[k]; //Neighbor cell [tx][ty]
                if(tx>=0 && tx<n && ty>=0 && ty<m && board[tx][ty]=='.') //Check if the neighbor is valid and not visited before.
                {
                    if(board[top.first][top.second] == 'W')
                        board[tx][ty] = 'B';
                    else
                        board[tx][ty] = 'W';

                    q.push(pii(tx,ty)); //Pushing a new pair in the queue
                }
            }
        }
    }
}
