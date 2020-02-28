#include<bits/stdc++.h>
using namespace std;

int r1, r2, T, cards[4][4],arrange1[4];

bool binarySearch(int key)
{
    int low = 0, high = 3, mid;
    //cout<<"BS"<<endl;
    while(low<=high)
    {
        mid = (low + high)/2;
        if(key == cards[r2][mid])
            return true;
        else if(key>cards[r2][mid])
            low = mid+1;
        else
            high = mid -1;
    }

    return false;
}

int main()
{
    freopen("A-small-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    int res,ret;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        //cout<<"here"<<endl;
        res=0,ret=-1;
        cin>>r1;
        r1--;
        for(int j=0;j<4;j++)
        {
            for(int k=0;k<4;k++)
            {
                cin>>cards[j][k];
            }
        }
        std::sort(cards[r1], cards[r1]+4);
        for(int j=0;j<4;j++)
            arrange1[j] = cards[r1][j];
        /*for(int j=0;j<4;j++)
            cout<<cards[r1][j]<<" ";*/

        cin>>r2;
        r2--;
        for(int j=0;j<4;j++)
        {
            for(int k=0;k<4;k++)
            {
                cin>>cards[j][k];
            }
        }
        std::sort(cards[r2], cards[r2]+4);
        /*for(int j=0;j<4;j++)
            cout<<cards[r2][j]<<" ";*/
        for(int j=0;j<4;j++)
        {
            if(binarySearch(arrange1[j]))
            {
                res++;
                if(ret==-1)
                    ret = arrange1[j];
            }
        }
        cout<<"Case #"<<i+1<<": ";
        if(!res)
            cout<<"Volunteer cheated!"<<endl;
        else if(res>1)
            cout<<"Bad magician!"<<endl;
        else
            cout<<ret<<endl;
    }
}
