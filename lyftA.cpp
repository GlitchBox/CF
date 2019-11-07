#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

int fx[]={1,-1,0,0,1,-1,-1,1};
int fy[]={0,0,1,-1,1,-1,1,-1};
int cell[1005][1005]; //cell[x][y]
int d[1005][1005],vis[1005][1005]; //d means destination from source.
int row,col;
int Ax,Ay,Bx,By,Cx,Cy,n;

void setCheck()
{
    //put check on the same row
    for(int j = 0;j<n;j++)
        cell[Ay][j] = -1;

    //put check on the same column
    for(int i=0;i<n;i++)
        cell[i][Ax] = -1;

    //put check on diagonals
    for(int i=Ay+1,j=Ax+1;(i<n && j<n);i++,j++)
        cell[i][j] = -1;

    for(int i=Ay-1,j=Ax-1;(i>=0 && j>=0);i--,j--)
        cell[i][j] = -1;

    for(int i=Ay-1,j=Ax+1;(i>=0 && j<n);i--,j++)
        cell[i][j] = -1;

    for(int i=Ay+1,j=Ax-1;(i<n && j>=0);i++,j--)
        cell[i][j] = -1;

        //cell[Ay][Ax]
}

bool bfs(int sx,int sy) //Source node is in [sx][sy] cell.
{
	memset(vis,0,sizeof vis);
	vis[sx][sy]=1;
	queue<pii>q; //A queue containing STL pairs
	q.push(pii(sx,sy));
	while(!q.empty())
	{
		pii top=q.front(); q.pop();
		for(int k=0;k<8;k++)
		{
			int tx=top.first+fx[k];
			int ty=top.second+fy[k]; //Neighbor cell [tx][ty]
			if(tx>=0 && tx<row && ty>=0 && ty<col && cell[tx][ty]!=-1 && vis[tx][ty]==0) //Check if the neighbor is valid and not visited before.
			{
				vis[tx][ty]=1;
				d[tx][ty]=d[top.first][top.second]+1;
				q.push(pii(tx,ty)); //Pushing a new pair in the queue
			}
		}
	}

	if(vis[Cy][Cx] == 1)
        return true;

    return false;
}

int main()
{
    cin>>n;
    cin>>Ax>>Ay;
    cin>>Bx>>By;
    cin>>Cx>>Cy;

    row = n;
    col = n;

    Ay = n - Ay;
    By = n - By;
    Cy = n - Cy;
    Ax--;
    Bx--;
    Cx--;
    setCheck();

    /*for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<cell[i][j]<<" ";
        }
        cout<<endl;
    }*/

    if(bfs(By,Bx))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}
